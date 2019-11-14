import sys, copy
input = lambda: sys.stdin.readline().rstrip()
        
def bfs():
    q1 = len(q[-1])
    q2 = q1
    while q2:
        q1 = len(q[-1])
        q2 = q1
        for i in range(q1):
            x, y, _ = q[-1][i]
            for i in range(4):
                temp_x = x+dx[i]
                temp_y = y+dy[i]
                if 0 <= temp_x < N and 0 <= temp_y < N:
                    if L <= abs(A[x][y] - A[temp_x][temp_y]) <= R and not vA[temp_x][temp_y]:
                        q[-1].append((temp_x, temp_y, A[temp_x][temp_y]))
                        vA[temp_x][temp_y] = True
                        q2 += 1
            q2 -= 1
        


N, L, R = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
dx = [1,0,-1,0]
dy = [0,1,0,-1]

for m in range(2000):
    q = []
    vA = [[False for _ in range(N)] for _ in range(N)]

    for i in range(N):
        for j in range(N):
            if not vA[i][j]:
                vA[i][j] = True
                q.append([(i,j,A[i][j])])
                bfs()
            if len(q[-1]) == 1:
                q.pop(-1)

    if len(q) == 0:
        break

    for unite in q:
        _sum = 0
        for i in range(len(unite)):
            _sum += unite[i][2]
        avg = _sum//len(unite)
        for x, y, _ in unite:
            A[x][y] = avg

print(m)