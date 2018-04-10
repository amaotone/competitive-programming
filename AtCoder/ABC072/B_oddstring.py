s = input()
print(''.join([c for i, c in enumerate(s) if i%2==0]))