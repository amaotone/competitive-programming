def main():
    n, k = map(int, input().split())
    cnt = 0
    if k==0:
        print(n**2)
        return
    for i in range(1, n+1):
        if i>k:
            cnt += i-k
            cnt += (n-i+1)//i*(i-k)
            cnt += max((n-i+1)%i-k, 0)
    print(cnt)

if __name__=='__main__':
    main()