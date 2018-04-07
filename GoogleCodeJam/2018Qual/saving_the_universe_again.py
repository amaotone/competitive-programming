def calc(P):
    ans = 0
    damage = 1
    for c in P:
        if c=='S':
            ans += damage
        elif c=='C':
            damage *= 2
    return ans

def swap(P):
    for i in reversed(range(len(P))):
        if P[i-1:i+1] == 'CS':
            return P[:i-1] + 'SC' + P[i+1:]
    return None
    
def main():
    T = int(input())
    for i in range(1, T+1):
        D, P = input().split()
        D = int(D)
        S_cnt = P.count('S')
        C_cnt = P.count('C')
        cnt = 0

        while calc(P)>D:
            cnt += 1
            P = swap(P)
            if P is None:
                cnt = 'IMPOSSIBLE'
                break
        
        print('Case #{}: {}'.format(i, cnt))

if __name__=='__main__':
    main()