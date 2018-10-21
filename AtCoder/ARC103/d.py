#!/usr/bin/env python

import math

def query(p, q, ds):
    p_dirs = []
    q_dirs = []
    for d in ds:
        p_dir = 1 if p>0 else -1
        q_dir = 1 if q>0 else -1

        p_dirs.append(p_dir)
        q_dirs.append(q_dir)

        p -= p_dir * d
        q -= q_dir * d

    res = ''
    for pd, qd in zip(p_dirs, q_dirs):
        if pd > 0 and qd > 0:
            res += 'R'
        elif pd > 0 and qd < 0:
            res += 'U'
        elif pd < 0 and qd > 0:
            res += 'D'
        else:
            res += 'L'

    print(res)


def solve():
    n = int(input())
    queries = [tuple(map(int, input().split())) for _ in range(n)]
    m = max(map(lambda x: abs(x[0]) + abs(x[1]), queries))
    a = list(map(lambda x: (abs(x[0]) + abs(x[1])) % 2, queries))
    if len(set(a)) != 1:
        print(-1)
        return
    ps = [t[0]+t[1] for t in queries]
    qs = [t[0]-t[1] for t in queries]

    n_arms = int(math.ceil(math.log2(m)))
    if ps[0] % 2 == 0:
        ds = [2**i for i in reversed(range(n_arms))] + [1]
    else:
        ds = [2**i for i in reversed(range(n_arms))]
    print(len(ds))
    print(' '.join(map(str, ds)))
    for p, q in zip(ps, qs):
        query(p, q, ds)

if __name__ == '__main__':
    solve()
