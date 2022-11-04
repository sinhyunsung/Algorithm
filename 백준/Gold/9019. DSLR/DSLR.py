import sys
from collections import deque

n=int(sys.stdin.readline().strip())



for i in range(n):
    a,b=map(int,sys.stdin.readline().split())
    bfs=deque()
    bfs.append([a,""])
    visit=[0 for i in range(10000)]
    while(a!=b):
        a,m=bfs.popleft()
        if visit[a]:
            continue
        visit[a]=1
        bfs.append([2*a%10000,m+"D"])
        bfs.append([a-1 if a>0 else 9999,m+"S"])
        bfs.append([a*10%10000+a//1000,m+"L"])
        bfs.append([a//10+a%10*1000,m+"R"])
    print(m)
