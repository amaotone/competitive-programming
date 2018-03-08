#!/usr/bin/env python
s = input()
ans = set('abcdefghijklmnopqrstuvwxyz')-set(s)
if len(ans)==0:
    print('None')
else:
    print(min(ans))