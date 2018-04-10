def main():
    n = input()
    if len(n) == 1:
        print(n)
        return
    if set(n[1:]) == {'9'}:
        print(int(n[0]) + 9 * (len(n) - 1))
        return
    print(9 * (len(n) - 1) + int(n[0]) - 1)


if __name__ == '__main__':
    main()
