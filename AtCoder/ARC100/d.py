#!/usr/bin/env python
from itertools import accumulate

N = int(input())
A = list(map(int, input().split()))
Acum = list(accumulate([0] + A))

def cumsum(left, right):
    # [i, j)
    return Acum[right] - Acum[left]

def find_best_cut(left, right, prev):
    prev = max(prev, left+1)
    now = prev
    res = now
    best = abs(cumsum(left, prev) - cumsum(prev, right))
    while True:
        now += 1
        score = abs(cumsum(left, now) - cumsum(now, right))
        if score < best:
            best = score
            res = now
        else:
            return res

left = 0
right = 0
best = float('inf')
for center in range(1, N-1):
    left = find_best_cut(0, center, left)
    right = find_best_cut(center, N, right)
        
    t = [cumsum(0, left), cumsum(left, center), cumsum(center, right), cumsum(right, N)]
    score = max(t) - min(t)
    if score < best:
        best = score
    
print(best)
