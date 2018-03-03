import numpy as np
from scipy.spatial import ConvexHull


def main():
    n = int(input())
    arr = np.zeros((n, 2))
    for i in range(n):
        arr[i, 0], arr[i, 1] = map(int, input().split())
    print(arr)

    if n == 2:
        print(0.5)
        print(0.5)
        return

    hull = ConvexHull(arr)
    print(hull.vertices)

    arr -= arr[hull.vertices, :].mean(axis=0)
    print(arr)

    vs = list(hull.vertices)
    degs = np.arctan2(arr[:, 1], arr[:, 0])
    degs = [degs[v] for v in vs]
    degs = [degs[-1] - 2 * np.pi] + degs + [degs[0] + 2 * np.pi]
    print(degs)
    degs = np.array([degs[i + 1] - degs[i -1] for i in range(1, len(degs)-2+1)])
    print(degs/degs.sum())

    for i in range(n):
        # 凸包内はほぼ0
        if i not in hull.vertices:
            print(0)
            continue

            # あとは角度で当分


if __name__ == '__main__':
    main()
