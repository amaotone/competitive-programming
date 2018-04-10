import bisect

n = int(input())
a = sorted(list(map(int, input().split())))
b = sorted(list(map(int, input().split())))
c = sorted(list(map(int, input().split())))
ans = 0
for bi in b:
    upper = bisect.bisect_left(a, bi)
    lower = n - bisect.bisect_right(c, bi)
    ans += upper * lower
print(ans)
