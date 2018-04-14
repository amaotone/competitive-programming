# for visible set

from math import *
def case():
    # input
    N, P = map(int, input().split())
    P_start = P
    cookies = []
    for i in range(N):
        w, h = map(int, input().split())
        cookies.append((min(w,h)*2, sqrt(w*w+h*h)*2-min(w,h)*2))
        P -= (w+h)*2
    
    cookies = sorted(cookies, reverse=True)
    # print(cookies)

    used = []
    for i in range(len(cookies)):
        cost_min = cookies[i][0]
        if P >= cost_min:
            P -= cost_min
            used.append(i)
    
    cookies = sorted([c for i, c in enumerate(cookies) if i in used], key=lambda x: x[1])
    for i in range(len(cookies)):
        cost_add = cookies[i][1]
        if P >= cost_add:
            P -= cost_add
        elif 0 <= P <= cost_add:
            return P_start
    return P_start - P


if __name__=='__main__':
    T = int(input())
    for t in range(1, T+1):
        print('Case #{}: {}'.format(t, case()))
