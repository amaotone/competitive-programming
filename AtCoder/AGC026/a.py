#!/usr/bin/env python
N = int(input())
A = list(map(int, input().split()))
prev = None
ans = 0
for a in A:
    if prev == a:
        ans += 1
        prev = None
    else:
        prev = a
print(ans)