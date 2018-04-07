a, b, c = sorted(map(int, input().split()))
diff = (c-a)+(c-b)
if diff%2==0:
    print(diff//2)
else:
    print(diff//2+2)