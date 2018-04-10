#/usr/bin/env python
def bipartilte_matching():
    res = 0
    

import numpy as np
N = int(input())
red = sorted([tuple(map(int, input().split())) for _ in range(N)], reverse=True)
blue = sorted([tuple(map(int, input().split())) for _ in range(N)], reverse=True) 
ref = np.zeros((N, N))
for r in range(N):
    for b in range(N):
        if red[r][0] < blue[b][0] and red[r][1] < blue[b][1]:
            ref[r, b] = 1
unsearched_red = list(range(N))
unsearched_blue = list(range(N))
cnt = 0
for b in range(N):
    for r in range(N):
        if ref[r, b] and (r in unsearched_red) and (b in unsearched_blue):
            cnt += 1
            unsearched_red.remove(r)
            unsearched_blue.remove(b) 
print(cnt)