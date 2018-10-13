#!/usr/bin/env python
N = int(input())
A = list(map(int, input().split()))
A = sorted([a-(i+1) for i, a in enumerate(A)])
m = A[N//2]
ans = 0
for a in A:
    ans += abs(a-m)
print(ans)