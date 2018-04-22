import numpy as np
N, C = map(int, input().split())
x = np.zeros(N, int)
v = np.zeros(N, int)
for i in range(N):
    x[i], v[i] = map(int, input().split())

gain_f = np.cumsum(v)-x
for i in range(1, N):
    gain_f[i] = max(gain_f[i-1], gain_f[i])

gain_b = np.cumsum(v[::-1])-(C-x[::-1])
for i in range(1, N):
    gain_b[i] = max(gain_b[i-1], gain_b[i])
    
turn_f = np.cumsum(v)-x*2
for i in range(1, N):
    turn_f[i] = max(turn_f[i-1], turn_f[i])

turn_b = np.cumsum(v[::-1])-(C-x[::-1])*2
for i in range(1, N):
    turn_b[i] = max(turn_b[i-1], turn_b[i])

turn_f = np.concatenate(([0], turn_f))
turn_b = np.concatenate(([0], turn_b))

ans = 0
for i in range(N):
    ans = max([ans, gain_f[i]+turn_b[N-1-i], gain_b[i]+turn_f[N-1-i]])
print(ans)