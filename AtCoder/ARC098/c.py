#!/usr/bin/env python
n = int(input())
s = input()
ans = float('inf')
E_total = s.count('E')
W_total = s.count('W')
cnt = {'E': 0, 'W': 0}
for i in range(n):
    turn = cnt['W'] + (E_total - cnt['E'])
    if s[i] == 'E':
        turn -= 1
    ans = min(ans, turn)
    cnt[s[i]] += 1
print(ans)
