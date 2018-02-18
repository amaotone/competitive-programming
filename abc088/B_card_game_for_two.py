n = int(input())
alist = map(int, input().split())
alice = []
bob = []
for i, a in enumerate(sorted(alist, reverse=True)):
    if i % 2 == 0:
        alice.append(a)
    else:
        bob.append(a)
print(sum(alice) - sum(bob))
