import sys
input = lambda: sys.stdin.readline().rstrip()

def distSum():
    _sum = 0
    for x,y in house:
        c_min = 53
        for kk in range(len(chicken)):
            if not visited[kk]:
                r,c = chicken[kk]
                if c_min > abs(x-r) + abs(y-c):
                    c_min = abs(x-r) + abs(y-c)
        _sum += c_min
    return _sum

def outchicken(m,ck,s):
    global _min
    if m == M:
        dis = distSum()
        if _min > dis:
            _min = dis
        return
    n_ck = len(ck)
    for st in range(s,n_ck):
        x,y = ck[st]
        if not visited[st]:
            visited[st] = True
            outchicken(m-1, ck,st)
            visited[st] = False

N, M = map(int, input().split())
vil = [list(map(int, input().split())) for _ in range(N)]
chicken = []
visited = []
house = []
for i in range(N):
    for j in range(N):
        if vil[i][j] == 2:
            chicken.append((i,j))
            visited.append(False)
        elif vil[i][j] == 1:
            house.append((i,j))

_min = 10000000
outchicken(len(chicken), chicken,0)

print(_min)