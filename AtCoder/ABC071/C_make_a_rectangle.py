#!/usr/bin/env python
n = int(input())
A = sorted(list(map(int, input().split())), reverse=True)
cnt = {}
tmp = None
for a in A:
    cnt[a] = cnt.get(a, 0) + 1 
    if cnt[a]>=4:
        print(a*a)
        break
    if cnt[a]==2:
        if tmp:
            print(tmp*a)
            break
        tmp=a
else:
    print(0)