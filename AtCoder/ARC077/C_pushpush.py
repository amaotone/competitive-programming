from collections import deque
n = int(input())
a = list(map(int, input().split()))
b = deque()
last = n%2==0
for i in range(n):
    if last:
        b.append(a[i])
    else:
        b.appendleft(a[i])
    last = not last
print(*b)
