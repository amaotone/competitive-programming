import heapq

def solve():
    N = int(input())
    W = list(map(int, input().split()))
    s = 0
    ans = 0
    ants = []
    for w in W:
        if len(ants)==0 or s <= w*6:
            heapq.heappush(ants, -w)
            ans += 1
            s += w
        else:
            m = -ants[0]
            if w < m and s-m <= w*6:
                heapq.heappop(ants)
                s = s - m + w
                heapq.heappush(ants, -w)
    return ans

if __name__=='__main__':
    T = int(input())
    for i in range(1, T+1):
        print('Case #{}: {}'.format(i, solve()))