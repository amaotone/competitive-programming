import sys

def solve():
    N = int(input())
    counter = {}
    remain = set(range(N))
    for i in range(N):
        pref = list(map(int, input().split()))
        D = pref[0]
        if D==-1:
            sys.exit(1)
        resp = None
        resp_cnt = float('inf')
        for j in range(D):
            p = pref[j+1]
            cnt = counter.get(p, 0) + 1
            counter[p] = cnt
            if cnt < resp_cnt and p in remain:
                resp = p
                resp_cnt = cnt
        if resp is None:
            print(-1, flush=True)
        else:
        print(resp, flush=True)
        remain.remove(resp)

if __name__=='__main__':
    T = int(input())
    for i in range(1, T+1):
        solve()