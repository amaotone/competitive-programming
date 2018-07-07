#!/usr/bin/env python
n, m, d = map(int, input().split())
if d == 0:
    step = n
else:
    step = max((n-d)*2, 0)
print(step*(m-1)/(n**2))