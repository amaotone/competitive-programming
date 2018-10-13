#!/usr/bin/env python
import itertools
import math
for N in range(2, 13):
    ans = 0
    cache = {}
    for tp in itertools.permutations(range(N-1), N-1):
        s = set()
        cnt = 0
        for i in tp:
            s |= {i, i+1}
            cnt += 1
            if len(s)==N:
                ans += cnt
                cache[cnt] = cache.get(cnt, 0) + 1
                break
    print(N, ans, math.factorial(N-1)*N-ans)
    print(cache)