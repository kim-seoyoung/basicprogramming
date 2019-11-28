import sys
input = lambda: sys.stdin.readline().rstrip()

def gcd(x, y):
    while y != 0:
        r = x%y
        x=y
        y=r
    return x

T = int(input())

for _ in range(T):
    r, b, k = map(int, input().split())
    if r < b:
        r,b = b,r

    g = gcd(r, b)
    r = r/g
    b = b/g

    if b*(k-1) + 1 >= r:
        print("OBEY")
    else:
        print("REBEL")