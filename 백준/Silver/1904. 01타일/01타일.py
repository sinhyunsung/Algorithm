a=int(input())
b=[0]*1000000
b[0]=1
b[1]=2
for i in range(2,1000000):
    b[i]=(b[i-1]+b[i-2])%15746

print(b[a-1])