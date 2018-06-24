def digit_sum(i):
    return sum(map(int, list(str(i))))

scores = [i/digit_sum(i) for i in range(1, 10000)]
scores = [i+1 for i, n in enumerate(scores) if n <= min(scores[i:])]