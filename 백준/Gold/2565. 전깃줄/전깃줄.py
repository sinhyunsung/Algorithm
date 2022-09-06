a=int(input())
b=[]

for i in range(a):
    b.append(list(map(int,input().split())))
b.sort()

dp=[]

for i in range(a):
    dpv=0
    for j in range(i):
        if b[i][1]>b[j][1] and dpv<dp[j]+1:
            dpv=dp[j]+1
    else:
        if dpv==0:
            dp.append(1)
        else:
            dp.append(dpv)

print(a-max(dp))