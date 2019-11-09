import sys
input = lambda: sys.stdin.readline().rstrip()

N, K = map(int, input().split())
items = [list(map(int, input().split())) for _ in range(N)]
bag = [[0 for _ in range(K+1)] for _ in range(N+1)]

for i in range(1,N+1):
    for j in range(1, K+1):
        if items[i-1][0] > j:
            bag[i][j] = bag[i-1][j]
        else:
            bag[i][j] = max(items[i-1][1] + bag[i-1][j-items[i-1][0]], bag[i-1][j])

print(bag[N][K])


#time over
# def inbag(m,n,items,w):
#     global bag,vmax
#     if m == n:
#         return
#     else:
#         for i in range(len(items)):
#             if w > K:
#                 break
#             bag.append(items[i])
#             wbag = sum(list(zip(*bag))[0])
#             vbag = sum(list(zip(*bag))[1])
#             if wbag <= K and vbag > vmax:
#                 vmax = vbag
#             item = items[i+1:]
#             inbag(m+1, n, item,wbag)
#             bag.pop(-1)

# N, K = map(int, input().split())
# items = [list(map(int, input().split())) for _ in range(N)]
# items = sorted(items, key = lambda x: (-x[0], -x[1]))
# bag = []
# vmax = 0

# inbag(0,N,items,0)

# print(vmax)