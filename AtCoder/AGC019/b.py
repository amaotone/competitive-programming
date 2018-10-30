#!/usr/bin/env python
from collections import Counter

s = list(input())
cnt = Counter(s)

ans = len(s) * (len(s) - 1) / 2 + 1
for v in cnt.values():
    ans -= v * (v - 1) / 2

print(int(ans))
