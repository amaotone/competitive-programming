#!/usr/bin/env python
import numpy as np
from collections import deque

N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)

def dfs(graph, v):
    used = {v}
    res = set()
    q = deque([v])
    while len(q):
        v = q.popleft()
        if res.issubset(set(graph[v])):
            res.add(v)
        for nxt in graph[v]:
            if nxt not in used:
                used.add(nxt)
                q.append(nxt)
    return res

ALL = set(range(N))
A = dfs(G, 0)
print(A)
B = dfs(G, list(ALL-A)[0])
print(B)
