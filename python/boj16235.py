import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().rstrip()

# N, M, K = map(int, input().split())
# land = [[5 for _ in range(N)] for _ in range(N)]
# A = [list(map(int, input().split())) for _ in range(N)]
# trees = defaultdict(lambda: [])
# for i in range(M):
#     x, y, t = map(int,input().split())
#     trees[(x-1,y-1)].append(t)
# dx = [-1,-1,-1,0,0,1,1,1]
# dy = [-1,1,0,-1,1,-1,1,0]
# k = 0
# cnt = M

# while k < K:
#     for x in range(N):
#         for y in range(N):
#             add_nu = 0
#             temp_tree = []
#             if trees[(x,y)]:
#                 tree = trees[(x,y)]
#                 while tree:
#                     t = tree.pop()
#                     if t <= land[x][y]:
#                         temp_tree.append(t+1)
#                         land[x][y] -= t
#                     else:
#                         add_nu += t//2
#                         cnt -= 1
#                 tree.extend(temp_tree)
#                 tree.sort(reverse = True)
 
#             add_nu += A[x][y]
#             land[x][y] += add_nu
            

#     for key,tree in trees.items():
#         if len(tree) > 0:
#             new = 0
#             for i in range(len(tree)):
#                 if tree[i] % 5 == 0:
#                     new += 1
#             if new > 0:
#                 x,y = key
#                 for n in range(8):
#                     temp_x = x+dx[n]
#                     temp_y = y+dy[n]
#                     if 0 <= temp_x < N and 0 <= temp_y < N:
#                         cnt += new
#                         trees[(temp_x, temp_y)].extend([1]*new)
            
#     k += 1
    
# print(cnt)

#timeover
N, M, K = map(int, input().split())
land = [[5 for _ in range(N+1)] for _ in range(N+1)]
A = [list(map(int, input().split())) for _ in range(N)]
trees = [list(map(int, input().split())) for _ in range(M)]
dx = [-1,-1,-1,0,0,1,1,1]
dy = [-1,1,0,-1,1,-1,1,0]
die = []
k = 0

while k < K:
    trees = sorted(trees, key = lambda x: -x[2])
    temp_tree = []
    while trees:
        x,y,t = trees.pop()
        if t <= land[x][y]:
            temp_tree.append([x,y,t+1])
            land[x][y] -= t
            if (t+1) % 5 == 0:
                for i in range(8):
                    temp_x = x+dx[i]
                    temp_y = y+dy[i]
                    if 0 < temp_x <= N and 0 < temp_y <=N:
                        temp_tree.append([temp_x, temp_y,1])
        else:
            die.append([x,y,t])

    trees.extend(temp_tree)
        
    while die:
        x,y,t = die.pop()
        land[x][y] += (t // 2)

    for i in range(N):
        for j in range(N):
            land[i+1][j+1] += A[i][j]

    k += 1
    
print(len(trees))
