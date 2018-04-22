a, b, c, x, y = map(int, input().split())
ans = a*x+b*y
for i in range(1, max(x, y)+1):
    if i <= min(x, y):
        ans = min(ans, ans-a-b+2*c)
    else:
        if x < y:
            ans = min(ans, ans-b+2*c)
        else:
            ans = min(ans, ans-a+2*c)
print(ans)