import sys
input = lambda: sys.stdin.readline().rstrip()

def get(x,y):
    if board[x][y]:
        q.append(board[x][y])
        board[x][y] = 0

def merge(i,j,di,dj):
    while q:
        x = q.pop(0)
        if not board[i][j]:
            board[i][j] = x
        elif board[i][j] == x:
            board[i][j] = x * 2
            i , j = i + di, j + dj
        else:
            i , j = i + di, j + dj
            board[i][j] = x

def move(k):
    if k == 1:
        for j in range(N):
            for i in range(N-1,-1,-1):
                get(i, j)
            merge(N-1, j, -1,0)
    elif k == 2:
        for j in range(N):
            for i in range(N):
                get(i, j)
            merge(0, j, 1,0)
    elif k == 3:
        for i in range(N):
            for j in range(N):
                get(i, j)
            merge(i, 0, 0, 1)
    elif k == 4:
        for i in range(N):
            for j in range(N-1,-1,-1):
                get(i, j)
            merge(i, N-1, 0, -1)

def solve(cnt):
    global ans, board
    if cnt == 5:
        for i in range(N):
            ans = max(ans, max(board[i]))
        return
    b1 = [x[:] for x in board]
    for k in [1,2,3,4]:
        move(k)
        solve(cnt+1)
        board = [x[:] for x in b1]


N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
q, ans = [], 0

solve(0)
print(ans)
