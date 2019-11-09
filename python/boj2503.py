import sys
input = lambda: sys.stdin.readline().rstrip()

def strike(n, cn):
    cnt = 0
    for i in range(len(n)):
        if n[i] == cn[i]:
            cnt += 1
    return cnt

def ball(n, cn):
    cnt = 0
    for i in range(len(n)):
        if n[i] != cn[i] and cn[i] in n:
            cnt += 1
    return cnt

N = int(input())
num_li = [str(a) + str(b) + str(c) for a in range(1,10) for b in range(1,10) for c in range(1,10)]
num_list = [i for i in num_li if (i[0] != i[1]) and (i[1] != i[2]) and (i[0] != i[2])]
num_li = num_list[:]

for _ in range(N):
    num, S, B = map(int, input().split())
    for i in range(len(num_list)):
        if strike(num_list[i], str(num)) == S and ball(num_list[i], str(num)) == B:
            continue
        elif num_list[i] in num_li:
            num_li.remove(num_list[i])
    # print(num_li)

print(len(num_li))