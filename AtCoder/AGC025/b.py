#!/usr/bin/env python
import math
import fractions

MOD = 998244353

def egcd(a, b):
    (x, lastx) = (0, 1)
    (y, lasty) = (1, 0)
    while b != 0:
        q = a // b
        (a, b) = (b, a % b)
        (x, lastx) = (lastx - q * x, x)
        (y, lasty) = (lasty - q * y, y)
    return (lastx, lasty, a)
 
def modinv(a, m):
    inv, _, _ = egcd(a, m)
    return inv % m

class Factorial:
    def __init__(n):
        self.fact = [1] * n
        self.inv = [1] * n
        for i in range(n):
            

cache = [-1] * 300001
def modc(a,b,m):
    if cache[b] > 0:
        return cache[b]
    c = 1
    for i in range(b):
        c = c * (a - i) % m
        c = c * modinv(i + 1,m) % m
    return c

def LCM(a, b):
    return a*b//fractions.gcd(a, b)

def diophantine(a,b,c):
    q, r = divmod(a, b)
    if r==0:
        return 0, c//b
    else:
        u, v = diophantine(b, r, c)
        return v, u-q*v

def indefinite_eq(n, a, b, k):
    na, nb = diophantine(a, b, k)
    lcm = LCM(a, b)
    na %= lcm // a
    nb = (k - na*a)//b
    while True:
        if 0 <= na <= n and 0 <= nb <= n:
            yield na, nb
        if nb < 0:
            break
        na += lcm // a
        nb -= lcm // b

def main():
    N, A, B, K = map(int, input().split())

    ans = 0
    for na, nb in indefinite_eq(N, A, B, K):
        ans += modc(N, min(na, N-na), MOD) * modc(N, min(nb, N-nb), MOD)
        ans %= MOD
    print(ans)

if __name__=='__main__':
    main()