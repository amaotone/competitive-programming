a, b = map(int, input().split())
cnt = 0
for i in range(a, b+1):
  if str(i)==''.join(reversed(str(i))):
    cnt+=1
print(cnt)
