# 01BFS

from collections import deque

k = int(input())
q = deque()
q.append(1)
d = [float("inf")] * k
d[1] = 1
while q:
    n = q.popleft()
    l, r = (n * 10) % k, (n + 1) % k
    if d[l] > d[n]:
        d[l] = d[n]
        q.appendleft(l)
    if d[r] > d[n] + 1:
        d[r] = d[n] + 1
        q.append(r)
print(d[0])
