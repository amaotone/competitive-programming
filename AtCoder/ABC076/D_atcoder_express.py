# TLE

import numpy as np


def speed(t, v, l, r):
    if t < l:
        return v + l - t
    if l <= t <= r:
        return v
    if r < t:
        return v + t - r


n = int(input())
ts = np.cumsum(np.array([0] + list(map(int, input().split()))))
vs = list(map(int, input().split()))
conditions = [(0, 0, 0)] + [(vs[i], ts[i], ts[i + 1]) for i in range(n)] + [(0, ts[-1], ts[-1])]

speeds = np.zeros((ts[-1] * 2 + 1, len(conditions)))
for t in range(ts[-1] * 2 + 1):
    for i, (v, l, r) in enumerate(conditions):
        speeds[t, i] = speed(t*0.5, v, l, r)

print(speeds.min(axis=1).sum() / 2)
