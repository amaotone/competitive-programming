import sys
import math

def main():
    t = int(input())
    for i in range(t):
        a = int(input())
        w = math.ceil(a/3)
        area = {i:0 for i in range(2,w)}
        checked = set()
        while True:
            x = min(area, key=lambda x: area[x])
            print(x, 2, flush=True)

            # update
            x, y = map(int, input().split())
            if x==0 and y==0:
                break
            if x==-1 and y==-1:
                sys.exit()
            if (x, y) not in checked:
                checked.add((x, y))
                for j in [-1, 0, 1]:
                    if not 2<=x+j<=w-1:
                        continue
                    area[x+j] += 1
            
if __name__=='__main__':
    main()