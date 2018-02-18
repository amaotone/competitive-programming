import numpy as np
from collections import deque

H, W = map(int, input().split())
board = np.ones((H, W))
for i in range(H):
    for j, c in enumerate(input()):
        if c == '#':
            board[i, j] = 0

history = np.zeros((H, W))
history[0, 0] = 1

dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
q = deque()
q.append((0, 0))
# 幅優先探索
while len(q):
    p = q.popleft()

    # ゴール
    if p == (H - 1, W - 1):
        break

    for d in dirs:
        nxt = (p[0] + d[0], p[1] + d[1])

        # 迷路外
        if not (0 <= nxt[0] < H and 0 <= nxt[1] < W):
            continue

        # 白マスでない
        if board[nxt[0], nxt[1]] == 0:
            continue

        # 訪問済
        if history[nxt[0], nxt[1]] != 0:
            continue

        q.append(nxt)
        history[nxt[0], nxt[1]] = history[p[0], p[1]] + 1

if history[-1, -1] == 0:
    print(-1)
else:
    print(int(board.sum() - history[-1, -1]))
