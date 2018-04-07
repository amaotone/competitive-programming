#!/usr/bin/env python
import math
Q = int(input())
for _ in range(Q):
    A, B = sorted(map(int, input().split()))
    ans = (A-1)+(B-1)

    mid_low = max(int(math.sqrt(A*B-1)), A+1)
    mid_high = (A*B-1)//mid_low
    print(ans-max((B-mid_high),0)+max(mid_low-A,0))