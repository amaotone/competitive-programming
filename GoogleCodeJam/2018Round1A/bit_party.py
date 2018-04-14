def case():
    # input
    R, B, C = map(int, input().split())
    M, S, P = [], [], []
    for i in range(C):
        m, s, p = map(int, input().split())
        M.append(m)
        S.append(s)
        P.append(p)

if __name__=='__main__':
    T = int(input())
    for t in range(1, T+1):
        print('Case #{}: {}'.format(t, case()))
