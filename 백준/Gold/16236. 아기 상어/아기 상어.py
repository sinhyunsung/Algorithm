import sys
from collections import deque

n=int(sys.stdin.readline().strip())

l=[]
l2=[]

for i in range(n):
    l.append(list(map(int,sys.stdin.readline().split())))
    l2.append([[0]*2 for i in range(n)])

size=2
eat=0
num=-1

bfs=deque()

result=0

for i in range(n):
    for j in range(n):
        if l[i][j]==9:
            bfs.append([j,i,0])
            l[i][j]=0

dx=[0,-1,1,0]
dy=[-1,0,0,1]
while(bfs):
    first=0
    while(bfs):
        x,y,t=bfs.popleft()
        for i in range(4):
            ax=x+dx[i]
            ay=y+dy[i]
            if ax>=0 and ax<n and ay>=0 and ay<n:

                if l2[ay][ax][0] == 0:

                    if l[ay][ax]==size:
                        bfs.append([ax,ay,t+1])
                        l2[ay][ax][0]=1
                    elif l[ay][ax]==0:
                        bfs.append([ax,ay,t+1])
                        l2[ay][ax][0]=1
                    elif l[ay][ax]<size:
                        l2[ay][ax][0]=2
                        l2[ay][ax][1]=t+1
                        if first==0:
                            first=t+1

    for i in range(n):
        for j in range(n):
            if l2[i][j][0]==1:
                l2[i][j][0]=0
            elif l2[i][j][0]==2:
                if first==l2[i][j][1] and first!=0:
                    l[i][j]=0
                    bfs.append([j,i,l2[i][j][1]])
                    result = first
                    first=0
                    eat+=1
                    if eat==size:
                        eat=0
                        size+=1
                l2[i][j]=[0,0]

print(result)


