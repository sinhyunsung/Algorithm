a=int(input())
b=[]
for i in range(a):
    b.append(int(input()))

for i in range(1,len(b)):
    for j in range(i,0,-1):
        if b[j]<b[j-1]:
            temp=b[j]
            b[j]=b[j-1]
            b[j-1]=temp
        else:
            break

for i in range(len(b)):
    print(b[i])