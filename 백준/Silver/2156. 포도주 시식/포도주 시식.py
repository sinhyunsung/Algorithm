a=int(input())

b=[]
for i in range(a):
    b.append(int(input()))

dp=[]
try:
    dp.append(b[0])
    dp.append(b[1]+b[0])
    dp.append(max(b[2]+b[1],b[2]+b[0],b[0]+b[1]))
    
    for i in range(3,a):
        dp.append(max(dp[i-1],dp[i-2]+b[i],dp[i-3]+b[i]+b[i-1]))
except:
    exit
print(max(dp))
