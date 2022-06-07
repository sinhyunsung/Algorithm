a=list(map(int,input().split()))

b=[]
c=[]



for i in range(a[0]):
    b.append(list(map(int,list(input()))))
    c.append([[0,0] for k in range(a[1])])

for i in range(a[0]):
    for j in range(a[1]):
        if b[i][j]==1:
            c[i][j][0],c[i][j][1]=1,1
            p=1
            while i-p>-1 and j-p>-1 and j+p<a[1]:
                if b[i-p][j-p]==1 and b[i-p][j+p]==1:
                    c[i][j][0]+=1
                    p+=1
                else:
                    break
            p=1
            while i+p<a[0] and j-p>-1 and j+p<a[1]:
                if b[i+p][j-p]==1 and b[i+p][j+p]==1:
                    c[i][j][1]+=1
                    p+=1
                else:
                    break

    
sumv=0
    
for i in range(a[0]):
    for j in range(a[1]):
        if c[i][j][1]>=1 and sumv==0:
            sumv=1
        elif c[i][j][1]!=0 and c[i][j][1]>sumv:
            for k in range(c[i][j][1],sumv,-1):
                if i+(k-1)*2<a[0] and sumv<c[i+(k-1)*2][j][0] and k<=c[i+(k-1)*2][j][0] and k>sumv:
                    sumv=k

print(sumv)