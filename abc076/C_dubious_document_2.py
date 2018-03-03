def main():
    s = input()
    t = input()
    for i in reversed(range(len(s)-len(t)+1)):
        for j, c in enumerate(s[i:i+len(t)]):
            if c!='?' and c!=t[j]:
                break
        else:
            ans = s[:i] + t + s[i+len(t):]
            print(ans.replace('?', 'a'))
            return
    print('UNRESTORABLE')

if __name__=='__main__':
    main()