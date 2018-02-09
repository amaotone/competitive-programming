n = int(input())
upper = list(map(int, input().split()))
lower = list(map(int, input().split()))
ans = 0
for i in range(n):
    ans = max(ans, sum(upper[:i+1])+sum(lower[i:]))
print(ans)
