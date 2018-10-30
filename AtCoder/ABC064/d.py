#!/usr/bin/env python
from collections import Counter

n = int(input())
s = input()
s_start = s

while '()' in s:
    s = s.replace('()', '')

cnt = Counter(s)
print('(' * cnt[')'] + s_start + ')' * cnt['('])
