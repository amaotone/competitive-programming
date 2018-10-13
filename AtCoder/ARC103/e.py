#!/usr/bin/env python

def solve():
    s = input()
    n = len(s)

    if s[0] != '1' or s[-1] != '0':
        print(-1)
        return
    for i in range(n // 2):
        if s[i] != s[-(i + 2)]:
            print(-1)
            return

    v = [i + 1 if c == '1' else 0 for (i, c) in enumerate(s)]
    v[-1] = n

    last = n
    for i, x in reversed(list(enumerate(v))):
        if x != 0:
            v[i] = last
            last = x
        else:
            v[i] = last

    for i, x in enumerate(v[:-1]):
        print(i + 1, x)


if __name__ == '__main__':
    solve()
