#!/usr/bin/env python
import numpy as np

def solve():
    mod = 1000000007
    N = int(input())
    va = np.array(list(map(int, input().split())))
    cum1 = np.arange(N+1).cumsum()
    cum2 = cum1.cumsum()
    cum3 = cum2.cumsum()
    default = (cum1[N] % mod) * va.sum() % mod
    if len(va) <= 2:
        print(default)
        return
    elif len(va) == 3:
        print(default-va[0]-va[-1])
    else:
        print(cum3)
        print(default-cum2[N])

if __name__=='__main__':
    solve()