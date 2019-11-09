import sys
input = lambda: sys.stdin.readline().rstrip()

N, M = map(int,input().split())
plate = [list(input()) for _ in range(N)]
Wplate = [['W','B','W','B','W','B','W','B'],['B','W','B','W','B','W','B','W']] * 4
Bplate = [['B','W','B','W','B','W','B','W'],['W','B','W','B','W','B','W','B']] * 4
cnt_li = []

for i in range(M-8+1):
    for j in range(N-8+1):
        cnt = 0
        for n in range(8):
            for m in range(8):
                if plate[j+n][i+m] != Bplate[n][m]:
                    cnt += 1
        cnt_li.append(cnt)

        cnt = 0
        for n in range(8):
            for m in range(8):
                if plate[j+n][i+m] != Wplate[n][m]:
                    cnt += 1
        cnt_li.append(cnt)

print(min(cnt_li))

