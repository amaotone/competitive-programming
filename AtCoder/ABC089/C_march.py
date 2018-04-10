import itertools

n = int(input())
names = {'M': 0, 'A': 0, 'R': 0, 'C': 0, 'H': 0}
for i in range(n):
    initial = input()[0]
    names[initial] = names.get(initial, 0) + 1

ans = 0
for a, b, c in itertools.combinations('MARCH', 3):
    ans += names[a] * names[b] * names[c]
print(ans)
