H, W, D = map(int, input().split())
p = {}
for i in range(H):
    for j, value in enumerate(map(int, input().split())):
        p[value] = (i, j)

cost = {}
for i in range(1, W * H + 1):
    cost[i] = cost[i - D] + abs(p[i][0] - p[i - D][0]) + abs(p[i][1] - p[i - D][1]) if i > D else 0

Q = int(input())
for _ in range(Q):
    L, R = map(int, input().split())
    print(cost[R] - cost[L])
