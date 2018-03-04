n = int(input())
s = input().replace(' ', '')
if len(set(s))==3:
    print('Three')
elif len(set(s))==4:
    print('Four')
