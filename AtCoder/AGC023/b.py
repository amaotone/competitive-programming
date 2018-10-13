import numpy as np
N = int(input())
alphabets = list('abcdefghijklmnopqrstuvwxyz')
A = np.zeros((N, N), dtype=int)
for i in range(N):
    for j, c in enumerate(input()):
        A[i,j] = alphabets.index(c)

B = np.concatenate([A, A], axis=0)
cnt = 0
for i in range(N):
    C = B[i:i+N, :]
    if (C==C.T).all():
        cnt += 1
print(cnt*N)