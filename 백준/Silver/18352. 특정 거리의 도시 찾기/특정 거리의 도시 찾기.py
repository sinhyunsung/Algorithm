from collections import deque

n,m,k,x=map(int,input().split())

d=[-1 for i in range(n+1)]

d[x]=0

g={}

for i in range(m):
    a,b=map(int,input().split())
    if a in g:
        g[a].append(b)
    else:
        g[a]=[]
        g[a].append(b)
    
    if b not in g:
        g[b]=[]

bfs=deque([x])

while bfs:
    now=bfs.popleft()
    for i in g[now]:
        if d[i]==-1:
            d[i]=d[now]+1
            bfs.append(i)

check=False

for i in range(n+1):
    if d[i]==k:
        print(i)
        check=True

if check==False:
    print(-1)
    