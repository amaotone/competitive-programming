s = input()
while s:
    for p in ('dreamer', 'eraser', 'dream', 'erase'):
        if s.endswith(p):
            s = s[:-len(p)]
            break
    else:
        break
print('YES' if s=='' else 'NO')