#!/usr/bin/env python

n, m = map(int, input().split())
l = []
l = [0] * n
for _ in range(m):
    a, b = map(int, input().split())  # 1-index
    l[a-1] += 1
    l[b-1] += 1

for i in l:
    print(i)
