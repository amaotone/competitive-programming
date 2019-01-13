#!/usr/bin/env python


def solve():
    N = list(map(int, input().split()))
    if 1 in N and 9 in N and 7 in N and 4 in N:
        print('YES')
    else:
        print('NO')


if __name__ == "__main__":
    solve()
