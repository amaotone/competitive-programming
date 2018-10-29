#!/usr/bin/env python

n = int(input())
a = list(map(int, input().split()))

cnt = 0
for i in a:
    while i % 2 == 0:
        cnt += 1
        i //= 2
print(cnt)
