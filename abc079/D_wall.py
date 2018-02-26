H, W = map(int, input().split())
cost = [list(map(int, input().split())) for _ in range(10)]
wall = [list(map(int, input().split())) for _ in range(H)]

# warshall-floyd
for k in range(10):
    for i in range(10):
        for j in range(10):
            cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j])

ans = 0
for i in range(H):
    for j in range(W):
        if wall[i][j] != -1:
            ans += cost[wall[i][j]][1]

print(ans)
