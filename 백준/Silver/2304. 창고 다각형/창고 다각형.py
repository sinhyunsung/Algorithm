li=[[1000,0] for i in range(1000)]
n=int(input())
for i in range(n):
    x,y=map(int,input().split())
    for idx in range(y):
        if li[idx][0]>x:
            li[idx][0]=x
        if li[idx][1] < x+1:
            li[idx][1] = x+1
sum=0

for i in li:
    sum+=i[1]-i[0] if i[1]-i[0]>=0 else 0
print(sum)


