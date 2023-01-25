import sys
from collections import deque

n,m=map(int,sys.stdin.readline().split())

bfs=deque()

dir= {}

for i in range(n+m):
    a, b = map(int, sys.stdin.readline().split())
    dir[a]=b

bfs.append([1,0])

visit=[0 for i in range(101)]

while(bfs):
    now,time=bfs.popleft()
    if now==100:
        print(time)
        break
    for i in range(1,7):
        if now+i<101 and visit[now+i]==0:
            if now+i in dir:
                bfs.append([dir[now+i],time+1])
            else:
                bfs.append([now+i,time+1])
            visit[now+i]=1
