# time..
import sys
input = lambda: sys.stdin.readline().rstrip()

def check():
    for t in range(N):
        st = t
        for i in range(H):
            if ladder[i][st]:
                st += 1
            elif st > 0 and ladder[i][st-1]:
                st -= 1
        if t != st:
            return False
    return True

def bfs(h,x,y):
    global ladder, ans
    if ans <= h:
        return
    if check():
        if ans > h:
            ans = h
        return
    if h == 3:
        return
    else:
        for i in range(y,H):
            k = x if i == y else 0
            for j in range(k,N-1):
                if not ladder[i][j]:
                    ladder[i][j] = 1
                    bfs(h+1,j+2,i)
                    ladder[i][j] = 0

N,M,H = map(int, input().split())
ladder = [[0 for _ in range(N)] for _ in range(H)]
ans = 30

for _ in range(M):
    v, h = map(int, input().split())
    ladder[v-1][h-1] = 1

bfs(0,0,0)
if ans < 4:
    print(ans)
else:
    print(-1)

