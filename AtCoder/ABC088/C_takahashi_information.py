def main():
    arr = []
    for i in range(3):
        arr.append(list(map(int, input().split())))
    b1 = arr[0][0] - arr[0][1]
    b2 = arr[0][1] - arr[0][2]
    a1 = arr[1][0] - arr[0][0]
    a2 = arr[2][0] - arr[1][0]
    for i in range(3):
        if arr[i][0] - arr[i][1] != b1 or arr[i][1] - arr[i][2] != b2 or arr[1][i] - arr[0][i] != a1 or arr[2][i] - \
                arr[1][i] != a2:
            print("No")
            return
    print("Yes")


if __name__ == '__main__':
    main()
