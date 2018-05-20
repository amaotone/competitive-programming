#!/usr/bin/env python
N = int(input())
cache = dict()
for i in range(1, N+1):
    p = int(input())
    cache[p] = cache.get(p-1, 0) + 1
print(max(cache.values()))