#!/usr/bin/env python
n = int(input())
a = list(map(int, input().split()))
total = sum(a)
ans = float('inf')
tmp = 0
for i in range(n):
    tmp += a[i]
    if i==n-1:
        continue
    ans = min(ans, abs(tmp-(total-tmp)))
print(int(ans))