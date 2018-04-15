import numpy as np

N = int(input())
X = np.array(list(map(int, input().split())))
idx = X.argsort()
res = np.zeros(N, dtype=int)
res[idx[:N//2]] = X[idx[N//2-1]]
res[idx[N//2:]] = X[idx[N//2]]
for i in range(N):
    print(res[i])