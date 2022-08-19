import sys
from collections import deque

n,m=map(int,sys.stdin.readline().split())
l=[]
for i in range(n):
    l.append(list(sys.stdin.readline().strip()))

bfs=deque()
bfs.append([0,0,1])

dx=[0,0,-1,1]
dy=[1,-1,0,0]


while(bfs):
    y,x,v=bfs.popleft()
    if x==m-1 and y==n-1:
        print(v)
        break
    for i in range(4):
        if m>x+dx[i]>=0 and n>y+dy[i]>=0:
            if l[y+dy[i]][x+dx[i]]=="1":
                bfs.append([y+dy[i],x+dx[i],v+1])
                l[y + dy[i]][x + dx[i]]="0"


