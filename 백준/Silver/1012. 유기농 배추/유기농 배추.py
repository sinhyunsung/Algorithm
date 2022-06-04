from collections import deque

def cycle(dq,li,x,y):
    while True:
        if len(dq)==0:
            break
        else:
            a=dq.pop()
            if a[0]>0 and li[a[0]-1][a[1]]==1:
                dq.append([a[0]-1,a[1]])
                li[a[0]-1][a[1]]=0
            if a[1]>0 and li[a[0]][a[1]-1]==1:
                dq.append([a[0],a[1]-1])
                li[a[0]][a[1]-1]=0
            if a[0]<y-1 and li[a[0]+1][a[1]]==1:
                dq.append([a[0]+1,a[1]])
                li[a[0]+1][a[1]]=0
            if a[1]<x-1 and li[a[0]][a[1]+1]==1:
                dq.append([a[0],a[1]+1])
                li[a[0]][a[1]+1]=0
                
dq=deque()
a=int(input())

for p in range(a):
    ans=0
    b=list(map(int,input().split()))
    c=[[0]*b[0] for i in range(b[1])]
    for i in range(b[2]):
        x,y=map(int,input().split())
        c[y][x]=1
    
    for i in range(b[1]):
        for j in range(b[0]):
            if c[i][j]==1:
                dq.append([i,j])
                c[i][j]=0
                cycle(dq,c,b[0],b[1])
                ans+=1
    print(ans)
    