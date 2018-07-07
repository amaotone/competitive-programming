import itertools
n, m, d = map(int, input().split())

cnt = 0
for q in itertools.product(list(range(n)), repeat=m):
    t = 0
    for i, j in zip(q, q[1:]):
        if abs(i-j) == d:
            cnt += 1
            t += 1
    print(q, t)
    
print(cnt / (n**m))
