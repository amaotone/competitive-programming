#!/usr/bin/env python

from fractions import gcd

N, M = map(int, input().split())
S = list(input())
T = list(input())

g = int(gcd(N, M))
l = N * M // g

for i, j in zip(S[::N//g], T[::M//g]):
    if i != j:
        print(-1)
        break
else:
    print(l)
