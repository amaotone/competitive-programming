#!/usr/bin/env python
from collections import Counter

n = int(input())
v = list(map(int, input().split()))

odd = [x for (i, x) in enumerate(v) if i % 2 == 1]
even = [x for (i, x) in enumerate(v) if i % 2 == 0]

odd_c = Counter(odd)
even_c = Counter(even)

odd_c = sorted(odd_c.items(), key=lambda x: x[1], reverse=True) + [(-1, 0)]
even_c = sorted(even_c.items(), key=lambda x: x[1], reverse=True) + [(-1, 0)]

if odd_c[0][0] != even_c[0][0]:
    print(n - odd_c[0][1] - even_c[0][1])
elif odd_c[0][1] + even_c[1][1] >= odd_c[1][1] + even_c[0][1]:
    print(n - odd_c[0][1] - even_c[1][1])
else:
    print(n - odd_c[1][1] - even_c[0][1])
