import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())

for _ in range(n):
    c , _sum = map(int, input().split())
    a = _sum // c
    b = _sum % c
    answer = (a**2) * (c-b) + ((a+1)**2) * b
    print(answer)