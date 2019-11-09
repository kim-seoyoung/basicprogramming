import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
near = [list(map(int, input().split())) for _ in range(N)]
path = []

for k in range(N):
    for i in range(N):
        for j in range(N):
            if near[i][k] and near[k][j]:
                near[i][j] = 1

for i in range(N):
    print(*near[i])



# timeover
# N = int(input())
# near = [list(map(int, input().split())) for _ in range(N)]
# desti = [[i for i in range(N)] for _ in range(N)]
# answer = [[0 for _ in range(N)] for _ in range(N)]

# for _ in range(N):
#     for i in range(N):
#         for j in range(N):
#             for m in range(N):
#                 for n in range(N):
#                     if answer[m][n] == 0 and near[i][j] == 1 and desti[m][n] == i:
#                         desti[m][n] = j
#                     if desti[m][n] == m and answer[m][n] == 0:
#                         answer[m][n] = 1

# print(*answer)
                    
