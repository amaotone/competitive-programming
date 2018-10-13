#!/usr/bin/env python
from fractions import gcd

def ng(a, b, c, add):
    return 0 < (b-a)%add < (b-c)

def solve():
    a, b, c, d = map(int, input().split())
    # 自明
    if d < b or a < b:
        return 'No'
    if c > b:
        return 'Yes'
    a %= b
    if a > c:
        return 'No'

    if d-b == 0:
        return 'Yes'

    if gcd(b, d-b) < b-c:
        return 'No'
    else:
        return 'Yes'
    
T = int(input())
for _ in range(T):
    print(solve())