kind,weight=map(int,input().split())

dp=[0 for i in range(weight+1)]

li=[]

for i in range(kind):
    li.append(list(map(int,input().split())))

for i in range(kind):
    for j in range(weight,li[i][0]-1,-1):
        if dp[j]<li[i][1]+dp[j-li[i][0]]:
            dp[j]=li[i][1]+dp[j-li[i][0]]

print(max(dp))