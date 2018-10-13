#!/usr/bin/env python


def solve():
    n = int(input())
    queries = [tuple(map(int, input().split())) for _ in range(n)]
    m = max(map(lambda x: abs(x[0]) + abs(x[1]), queries))
    a = list(map(lambda x: (abs(x[0]) + abs(x[1])) % 2, queries))
    if len(set(a)) != 1:
        print(-1)
        return
    else:
        print(m)
        print(' '.join(['1'] * m))
        for (x, y) in queries:
            s = ''
            if x > 0:
                s += 'R' * abs(x)
            else:
                s += 'L' * abs(x)
            if y > 0:
                s += 'U' * abs(y)
            else:
                s += 'D' * abs(y)
            s += 'UD' * ((m - len(s)) // 2)
            print(s)


if __name__ == '__main__':
    solve()
