a=int(input())
b=list(map(int,input().split()))


dp=[]

for i in range(a):
    if i==0:
        dp.append(1)
    else:
        v=0
        for j in range(i):
            if b[i]>b[j] and v<dp[j]+1:
                v=dp[j]+1
        if v==0:
            dp.append(1)
        else:
            dp.append(v)

print(max(dp))