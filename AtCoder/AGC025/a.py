#!/usr/bin/env python
N = int(input())

def digit_sum(n):
    return sum(map(int, list(str(n))))

ans = float('inf')
for i in range(1, N):
    a = digit_sum(i)
    if a > ans:
        continue
    ans = min(ans, a + digit_sum(N-i))
print(ans)