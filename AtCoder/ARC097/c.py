#!/usr/bin/env python

def solve():
    s = input()
    k = int(input())
    subs = sorted([s[i:] for i in range(len(s))])

    cnt = 0
    checked = set()
    for sub in subs:
        for i in range(len(sub)):
            term = sub[:i+1]
            if term not in checked:
                cnt += 1
                checked.add(term)
                if cnt == k:
                    print(term)
                    return


solve()
