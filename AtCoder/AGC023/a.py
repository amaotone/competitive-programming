import numpy as np
N = int(input())
A = np.array(list(map(int, input().split())))
Acum = A.cumsum()
cache = {}
cnt = 0
for i in range(N):
    if Acum[i]==0:
        cnt += 1
    c = cache.get(Acum[i], 0)
    cnt += c
    cache[Acum[i]] = c+1
print(cnt)
