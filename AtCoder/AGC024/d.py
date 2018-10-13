#!/usr/bin/env python
import numpy as np
from copy import deepcopy
from collections import deque
N = int(input())
graph = np.zeros((N, N))
graph[:] = np.inf
graph_list = [[] for _ in range(N)]
dim = np.array([0]*N)
for _ in range(N-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a, b] = 1
    graph[b, a] = 1
    graph_list[a].append(b)
    graph_list[b].append(a)
    dim[a] += 1
    dim[b] += 1

# warshall-floyd
cost = graph.copy()
for k in range(N):
    for i in range(N):
        for j in range(N):
            if cost[i, j] > cost[i, k] + cost[k, j]:
                cost[i, j] = cost[i, k] + cost[k, j]
longest = int(cost[cost!=np.inf].max()+1)
depth = (longest+1)//2
roots = [i for i, c in enumerate(cost.max(axis=1)) if c==depth-1]

# dfs
levels = {i: [] for i in range(depth)}
cache = set(roots)
q = deque([(v, 0) for v in cache])
while len(q):
    v, level = q.popleft()
    levels[level].append(v)
    for nxt in graph_list[v]:
        if nxt not in cache:
            cache.add(nxt)
            q.append((nxt, level+1))

ans=1
for lv in range(0, N-1):
    ans *= max([len(graph_list[v]) for v in levels[lv]])