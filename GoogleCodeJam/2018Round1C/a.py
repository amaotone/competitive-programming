import operator
from functools import reduce
import itertools

def solve():
    N, L = map(int, input().split())
    chars = [set() for _ in range(L)]
    words = []
    for _ in range(N):
        word = input()
        words.append(word)
        for i, c in enumerate(word):
            chars[i] |= {c}
    if N==reduce(operator.mul, map(len, chars), 1):
        return '-'
    for word in itertools.product(*chars):
        w = ''.join(word)
        if w not in words:
            return w
            
if __name__=='__main__':
    T = int(input())
    for i in range(1, T+1):
        print('Case #{}: {}'.format(i, solve()))