a=int(input())
b=[]
for i in range(a):
    b.append(list(map(int,input().split())))

for i in range(len(b)):
    sumv=1
    for j in range(len(b)):
        if i!=j and b[i][0] < b[j][0] and b[i][1] < b[j][1]:
            sumv+=1
    print(sumv,end=' ')