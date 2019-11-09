import sys
input = lambda: sys.stdin.readline().rstrip()

N, S = map(int, input().split())
nums = list(map(int, input().split()))
cnt = 0

for i in range(2 ** N):
    temp = i
    li = []
    for j in range(N):
        if temp % 2 == 1:
            li.append(nums[j])
        temp = temp // 2
    if li != [] and sum(li) == S:
        cnt += 1

print(cnt)