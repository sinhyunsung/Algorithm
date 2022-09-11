a=int(input())
b=[]

for i in range(a):
    b.append([int(input()),0,0,0])

for i in range(a):
    if i==0:
        b[i][1],b[i][2],b[i][3]=b[i][0],0,0
    elif i==1:
        b[i][1]=b[i][0]
        b[i][2]=b[i-1][1]+b[i][0]
        b[i][3]=0
    else:
        b[i][1]=max(b[i-2][1]+b[i][0],b[i-2][2]+b[i][0])
        b[i][2]=b[i-1][1]+b[i][0]
        b[i][3]=max(b[i-1][1],b[i-1][2])

print(max(b[a-1][1],b[a-1][2]))