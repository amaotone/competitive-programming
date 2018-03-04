H, W, D = map(int, input().split())
p = {}
for i in range(H):
    inp = list(map(int, input().split()))
    for j, value in enumerate(inp):
        p[value] = (i, j)

cost = {i: 0 for i in range(1, D + 1)}
for i in range(1, D + 1):
    now = i + D
    while now <= H * W:
        cost[now] = cost[now - D] + abs(p[now][0] - p[now - D][0]) + abs(p[now][1] - p[now - D][1])
        now += D

Q = int(input())
for _ in range(Q):
    L, R = map(int, input().split())
    print(cost[R] - cost[L])
