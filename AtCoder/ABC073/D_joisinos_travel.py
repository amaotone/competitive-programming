#!/usr/bin/env python
# ワーシャルフロイド+全探索

import numpy as np
import itertools

def main():
    N, M, R = map(int, input().split())
    rs = list(map(int, input().split()))
    inf = float('inf')
    cost = [[inf]*N for _ in range(N)]

    # グラフ作る
    for i in range(N):
        cost[i][i] = 0

    for _ in range(M):
        a, b, c = map(int, input().split())
        cost[a-1][b-1] = c
        cost[b-1][a-1] = c
    
    # ワーシャルフロイドで全頂点間距離算出
    for k in range(N):
        for i in range(N):
            for j in range(N):
                if cost[i][k]+cost[k][j] < cost[i][j]:
                    cost[i][j] = cost[i][k] + cost[k][j]

    # 組み合わせ全探索
    ans = inf
    for route in itertools.permutations(rs):
        d = 0
        for i in range(R-1):
            d += cost[route[i]-1][route[i+1]-1]
            if d > ans:
                break
        ans = min(ans, d)
    
    print(int(ans))


if __name__=='__main__':
    main()