#!/usr/bin/env python
def solve(N, S):
    if S[N-1] != S[N]:
        return 0

    
N = int(input())
S = input()
print(solve(N, S))