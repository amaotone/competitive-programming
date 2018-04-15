#!/usr/bin/env python
"""WA"""
import numpy as np
from copy import deepcopy
from collections import Counter

def main():
    H, W = map(int, input().split())
    area = np.array([list(input()) for _ in range(H)])

    hcounts = [Counter(area[i, :]) for i in range(H)]
    vcounts = [Counter(area[:, i]) for i in range(W)]

    h_paired, v_paired = set(), set()
    h_pairs, v_pairs = [], []
    for i in range(H):
        if i in h_paired:
            continue
        for j in range(i+1, H):
            if j in h_paired:
                continue
            if hcounts[i]==hcounts[j]:
                h_paired |= {i, j}
                h_pairs.append((i, j))
    
    for i in range(W):
        if i in v_paired:
            continue
        for j in range(i+1, W):
            if j in v_paired:
                continue
            if vcounts[i]==vcounts[j]:
                v_paired |= {i, j}
                v_pairs.append((i, j))
    
    if H-len(h_paired) >= 2 or W-len(v_paired) >= 2:
        print('NO')
        return

    # 実際にならべなおす
    # print(h_pairs, v_pairs)
    h_pos = list(range(H))
    v_pos = list(range(W))
    area_orig = deepcopy(area)

    for i, (a, b) in enumerate(h_pairs):
        area[i, :] = area_orig[a, :]
        area[H-1-i, :] = area_orig[b, :]
    for c in set(range(H))-h_paired:
        area[H//2, :] = area_orig[c, :]
    
    area_orig = deepcopy(area)
    for i, (a, b) in enumerate(v_pairs):
        area[:, i] = area_orig[:, a]
        area[:, W-1-i] = area_orig[:, b]
    for c in set(range(W))-v_paired:
        area[:, W//2] = area_orig[:, c]
    
    for i in range(H):
        for j in range(W):
            if area[i, j] != area[H-i-1, W-j-1]:
                print('NO')
                return
    print('YES')
            

if __name__=='__main__':
    main()