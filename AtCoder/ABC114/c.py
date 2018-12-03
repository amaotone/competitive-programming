#!/usr/bin/env python
# 全探索すればよい
import itertools


def solve():
    n = int(input())
    cnt = 0
    for i in range(1, 11):
        for res in itertools.product(['3', '5', '7'], repeat=i):
            if int(''.join(res)) > n:
                print(cnt)
                return
            if '3' in res and '5' in res and '7' in res:
                cnt += 1


if __name__ == '__main__':
    solve()
