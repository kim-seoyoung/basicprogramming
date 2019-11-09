import sys
input = lambda: sys.stdin.readline().rstrip()

N, S = map(int, input().split())
nums = list(map(int, input().split()))
cnt = 0
num_li = []

def recur(li, n,s):
    global num_li, cnt
    if n == 0:
        return
    else:
        for i in range(len(li)):
            num_li.append(li[i])
            if sum(num_li) == s:
                cnt += 1
            temp = li[i+1:]
            recur(temp, n-1,s)
            num_li.pop(-1)
            
recur(nums, N, S)

print(cnt)