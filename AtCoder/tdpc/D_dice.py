#!/usr/bin/env python
N, D = map(int, input().split())
x, y, z = (0, 0, 0)
while D%5==0:
    z += 1
    D //= 5
while D%3==0:
    y += 1
    D //= 3
while D%2==0:
    x += 1
    D //= 2

if D!=1:
    print(0)

from collections import defaultdict
dp = defaultdict(int)
dp[(0, 0, 0)] = 1
for i in range(N):
    for (a, b, c), cnt in dp.copy().items():
        dp[(min(a+1, x), b, c)] += cnt
        dp[(a, min(b+1, y), c)] += cnt
        dp[(min(a+2, x), b, c)] += cnt
        dp[(a, b, min(c+1, z))] += cnt
        dp[(min(a+1, x), min(b+1, y), c)] += cnt
print(dp[(x, y, z)]/(6**N))