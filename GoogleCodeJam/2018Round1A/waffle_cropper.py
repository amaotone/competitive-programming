def cumsum_1d(lst):
    res = [0]*len(lst)
    res[0] = lst[0]
    for i in range(1, len(lst)):
        res[i] = res[i-1] + lst[i]
    return res

def cumsum_2d(area):
    height = len(area)
    width = len(area[0])
    res = [[0]*width for _ in range(height)]
    
    for i in range(height):
        for j in range(width):
            if j==0:
                res[i][j] = area[i][j]
            else:
                res[i][j] = res[i][j-1] + area[i][j]

    for i in range(height):
        for j in range(width):
            if i!=0:
                res[i][j] = res[i-1][j] + res[i][j]

    return res

def case():
    R, C, H, V = map(int, input().split())
    hcnt = [0]*R
    vcnt = [0]*C
    total = 0
    area = [[0]*C for _ in range(R)]
    
    for i in range(R):
        row = input()
        for j, c in enumerate(row):
            if c=='@':
                area[i][j] = 1
                hcnt[i] += 1
                vcnt[j] += 1
                total += 1

    if total%((H+1)*(V+1))!=0 or total%(H+1)!=0 or total%(V+1)!=0:
        return 'IMPOSSIBLE'

    each = total//((H+1)*(V+1))
    area_cumsum = cumsum_2d(area)
    h_cumsum = cumsum_1d(hcnt)
    v_cumsum = cumsum_1d(vcnt)

    hcuts = []
    vcuts = []

    for i in range(1, H+2):
        target = total//(H+1)*i
        if target not in h_cumsum:
            return 'IMPOSSIBLE'
        else:
            hcuts.append(h_cumsum.index(target))

    for i in range(1, V+2):
        target = total//(V+1)*i 
        if target not in v_cumsum:
            return 'IMPOSSIBLE'
        else:
            vcuts.append(v_cumsum.index(target))
    
    for i, hcut in enumerate(hcuts):
        for j, vcut in enumerate(vcuts):
            if area_cumsum[hcut][vcut] != each*((i+1)*(j+1)):
                return 'IMPOSSIBLE'

    return 'POSSIBLE'


if __name__=='__main__':
    T = int(input())
    for t in range(1, T+1):
        print('Case #{}: {}'.format(t, case()))