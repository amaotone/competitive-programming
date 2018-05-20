#!/usr/bin/env python
def solve():
    N = int(input())
    ans = 0
    prev = None
    for _ in range(N):
        a = int(input())    
        if prev is None and a!=0:
            return -1
        if prev is not None:
            diff = a - prev
            if diff >= 2:
                return -1
            elif diff <= 0:
                ans += prev
        prev = a
    ans += prev
    return ans

if __name__=='__main__':
    print(solve())