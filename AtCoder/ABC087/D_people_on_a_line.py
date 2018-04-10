from collections import deque

def main():
    N, M = map(int, input().split())
    link = [[] for _ in range(N+1)]
    value = [0 for _ in range(N+1)]

    for _ in range(M):
        l, r, d = map(int, input().split())
        link[l].append((r, d))
        link[r].append((l, -d))

    searched = set()
    q = deque()
    for u in range(N+1):
        if u in searched:
            continue
        q.append(u)
        searched.add(u)
        value[u] = 0

        # search
        while q:
            x = q.popleft()
            for y, d in link[x]:
                if y not in searched:
                    value[y] = value[x] + d
                    q.append(y)
                    searched.add(y)

    # verify
    for x in range(N+1):
        for y, d in link[x]:
            if value[y] != value[x] + d:
                print('No')
                return
    else:
        print('Yes')

if __name__ == '__main__':
    main()