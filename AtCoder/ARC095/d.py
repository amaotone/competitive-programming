#!/usr/bin/env python
N = int(input())
A = sorted(map(int, input().split()))

n = A[-1]
r = sorted(A[:-1], key=lambda x: abs(x-n/2))[0]
print(n, r)