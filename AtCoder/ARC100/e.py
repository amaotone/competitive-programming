#!/usr/bin/env python
N = int(input())
A = np.array(list(map(int, input().split())))
print(A.argsort())