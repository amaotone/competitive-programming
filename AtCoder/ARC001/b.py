#!/usr/bin/env python
import math
ref = [0, 1, 2, 3, 2, 1, 2, 3, 3, 2]
a, b = map(int, input().split())
d = abs(a - b)
print(d // 10 + ref[d % 10])
