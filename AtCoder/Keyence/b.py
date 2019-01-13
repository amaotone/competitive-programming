#!/usr/bin/env python


def solve():
    S = input()
    for i in range(len('keyence')+1):
        if S.startswith('keyence'[:i]) and S.endswith('keyence'[i:]):
            print('YES')
            return
    print('NO')


if __name__ == "__main__":
    solve()
