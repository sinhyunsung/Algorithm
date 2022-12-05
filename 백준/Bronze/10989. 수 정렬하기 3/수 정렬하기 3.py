import sys
N = int(sys.stdin.readline())
list1 = [0] * 10000
for i in range(N):
    new = int(sys.stdin.readline())
    list1[new - 1] += 1

cnt = 0
i = 0
while cnt < N:
    if list1[i] >= 0:
        cnt += list1[i]
        for j in range(list1[i]):
            print(i + 1)
        i += 1