#!/usr/bin/env python
n = int(input())
for i in range(8):
    if 2**(i+1)>n:
        print(2**i)
        break