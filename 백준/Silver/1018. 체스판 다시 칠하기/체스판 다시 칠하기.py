
a=list(map(int,input().split()))
b=[]
c=[]
for i in range(a[0]):
    b.append(input())

for i in range(a[0]-7):
    for j in range(a[1]-7):
        sumb=[0,'B']
        sumw=[0,'W']
        for k in range(8):
            for l in range(8):
                if b[i+k][j+l]==sumb[1]:
                    sumb[0]+=1
                else:
                    sumw[0]+=1
                temp=sumb[1]
                sumb[1]=sumw[1]
                sumw[1]=temp
            temp=sumb[1]
            sumb[1]=sumw[1]
            sumw[1]=temp
        if sumb[0]>=sumw[0]:
            c.append(sumw[0])
        else:
            c.append(sumb[0])
print(min(c))