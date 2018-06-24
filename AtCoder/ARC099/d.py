def digit_sum(i):
    return sum(map(int, list(str(i))))

def score(head, tail):
    return num(head, tail)/digit_sum(num(head, tail))

def num(head, tail):
    return int(str(head)+tail)

k = int(input())
tail = ''
head = 0
cnt = 0
last = 0
while True:
    head += 1
    if score(head, tail) <= score(head+1, tail):
        if num(head, tail) > last:
            print(str(head)+tail)
            last = num(head, tail)
            cnt += 1
            if cnt == k:
                break
    else:
        head = 0
        tail += '9'