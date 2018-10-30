#!/usr/bin/env python
import math

import numpy as np

n = int(input())
flag = np.ones(55555 + 1)

for i in range(2, int(math.sqrt(55555)) + 1):
    if flag[i] == 0:
        continue
    for j in range(2, 55555 // i + 1):
        flag[i * j] = 0

t = [i for i in range(2, 55555 + 1) if flag[i] == 1 and i % 5 == 1]

print(' '.join(map(str, t[:n])))
