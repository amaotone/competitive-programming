def trouble_sort(lst):
    done = False
    while not done:
        done = True
        for i in range(len(lst)-2):
            if lst[i] > lst[i+2]:
                done = False
                lst[i], lst[i+2] = lst[i+2], lst[i]
    return lst

def main():
    T = int(input())
    for i in range(1, T+1):
        N = int(input())
        V = list(map(int, input().split()))
        for j, (a, b) in enumerate(zip(sorted(V), trouble_sort(V))):
            if a!=b:
                print('Case #{}: {}'.format(i, j))
                break
        else:
            print('Case #{}: OK'.format(i))

if __name__=='__main__':
    main()