#!/usr/bin/env python


def solve():
    N, H, W = map(int, [input() for _ in range(3)])
    print((N - H + 1) * (N - W + 1))


if __name__ == '__main__':
    solve()
