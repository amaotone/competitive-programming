#!/usr/bin/env python
n = int(input())
va = list(map(int, input().split()))

res = set()
cnt = 0
for a in va:
    if a // 400 < 8:
        res.add(a // 400)
    else:
        cnt += 1

if len(res) == 0:
    print(1, cnt)
else:
    print(len(res), len(res) + cnt)
