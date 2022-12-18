a=int(input())
d=[]
for i in range(a):
    
    d.append(list(map(int,input().split())))
    tmp=d[i][1]
    d[i][1]=d[i][0]
    d[i][0]=tmp
d.sort()

for i in range(a):
    print(d[i][1],d[i][0])
