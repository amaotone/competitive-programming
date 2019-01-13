#!/usr/bin/env python
import numpy as np


def solve():
    N = int(input())
    A = np.array(list(map(int, input().split())))
    B = np.array(list(map(int, input().split())))

    # 自明
    if sum(A) < sum(B):
        print(-1)
        return

    # できるとき
    few = A < B
    few_cnt = few.sum()
    few_sum = (B - A)[few].sum()
    if few_cnt == 0:
        print(0)
        return

    over = (A >= B)
    overs = (A - B)[over]
    overs.sort()
    overs_cumsum = overs[::-1].cumsum()
    for i, v in enumerate(overs_cumsum):
        if v >= few_sum:
            print(few_cnt + i + 1)
            return


if __name__ == "__main__":
    solve()
