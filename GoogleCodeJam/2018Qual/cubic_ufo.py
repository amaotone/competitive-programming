from math import *

def newton(f, g, x, eps=1e-8):
    while abs(f(x)) > eps:
        x -= f(x)/g(x)
    return x

def rotate(x, y, z, rx=0, rz=0):
    # x rotate
    y, z = y*cos(rx)-z*sin(rx), y*sin(rx)+z*cos(rx)
    # z rotate
    x, y = x*cos(rz)-y*sin(rz), x*sin(rz)+y*cos(rz)
    return (x, y, z)

T = int(input())
for i in range(1, T+1):
    A = float(input())
    x = 0.5
    d45 = pi/4
    print('Case #{}:'.format(i))
    if A <= sqrt(2):
        theta = newton(
            f=lambda theta: sqrt(2)*cos(d45-theta)-A,
            g=lambda theta: sqrt(2)*sin(d45-theta),
            x=0
        )
        # print(degrees(theta))
        print(*rotate(0.5, 0, 0, theta))
        print(*rotate(0, 0.5, 0, theta))
        print(*rotate(0, 0, 0.5, theta))
    else:
        alpha = acos(1/sqrt(3))
        theta = newton(
            f=lambda theta: sqrt(2)/2*cos(theta)+sqrt(6)/2*cos(alpha-theta)-A,
            g=lambda theta: -sqrt(2)/2*sin(theta)+sqrt(6)/2*sin(alpha-theta),
            x=0
        )
        # print(degrees(theta%(2*pi)))
        print(*rotate(0.5, 0, 0, d45, theta))
        print(*rotate(0, 0.5, 0, d45, theta))
        print(*rotate(0, 0, 0.5, d45, theta))
        