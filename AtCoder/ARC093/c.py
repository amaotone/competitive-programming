#!/usr/bin/env python
n = int(input())
va = [0] + list(map(int, input().split())) + [0]
diffs = []

total = 0
for i, j in zip(va, va[1:]):
    total += abs(j-i)

for i, j, k in zip(va, va[1:], va[2:]):
    print(total-(abs(j-i)+abs(k-j)-abs(k-i)))

