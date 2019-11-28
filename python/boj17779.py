import sys
input = lambda: sys.stdin.readline().rstrip()

def splitele(x,y,d1,d2):
    land = [[0 for _ in range(N)] for _ in range(N)]
    for i in range(d2+1):
        for j in range(d1+1):
            land[y+i-j-1][x+i+j-1] = 5

    for i in range(d2):
        for j in range(d1):
            land[y+i-j-1][x+i+j] = 5

    for i in range(x+d1):
        for j in range(y-1):
            if not land[j][i]:
                land[j][i] = 1

    for i in range(x+d1,N):
        for j in range(y-d1+d2):
            if not land[j][i]:
                land[j][i] = 2

    for i in range(x+d2-1):
        for j in range(y-1,N):
            if not land[j][i]:
                land[j][i] = 3

    for i in range(x+d2-1,N):
        for j in range(y-d1+d2,N):
            if not land[j][i]:
                land[j][i] = 4

    return land


N = int(input())
popul = [list(map(int, input().split())) for _ in range(N)]
_min = 100*N

for r in range(N-2):
    for c in range(1,N-1):
        b1 = 1
        while c-b1 >= 0:
            b2 = 1
            while  c+b2 < N:
                if r+b1+b2 >= N:
                    break
                l_sum = [0,0,0,0,0]
                land = splitele(r,c,b1,b2)

                for i in range(N):
                    for j in range(N):
                        if land[i][j] == 1:
                            l_sum[0] += popul[i][j]
                        elif land[i][j] == 2:
                            l_sum[1] += popul[i][j]
                        elif land[i][j] == 3:
                            l_sum[2] += popul[i][j]
                        elif land[i][j] == 4:
                            l_sum[3] += popul[i][j]
                        elif land[i][j] == 5:
                            l_sum[4] += popul[i][j]

                diff = max(l_sum) - min(l_sum)
                if _min > diff:
                    _min = diff

                b2 += 1
            b1 += 1

print(_min)


