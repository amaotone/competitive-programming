#!/usr/bin/env python
H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]
ds = [(-1, -1), (0, -1), (1, -1), (-1, 0), (1, 0), (-1, 1), (0, 1), (1, 1)]
for i in range(H):
    for j, c in enumerate(A[i]):
        if c == '.':
            cnt = 0
            for d in ds:
                x = j + d[0]
                y = i + d[1]
                if 0 <= x <= W - 1 and 0 <= y <= H - 1 and A[y][x] == '#':
                    cnt += 1
            A[i][j] = str(cnt)

for i in range(H):
    print(''.join(A[i]))
