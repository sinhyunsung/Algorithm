from collections import deque

dq=deque()
a=[]
a.append(int(input()))
a.append(int(input()))
a.append(1)


b=[[] for i in range(a[0]+1)]
f=[]
for i in range(a[1]):
    c,d=map(int,input().split())
    b[c].append(d)
    b[d].append(c)
for i in range(len(b)):
    b[i].sort()


dq.append(a[2])
f=[]

while len(dq)!=0:
    e=dq.popleft()
    f.append(e)
    for i in range(len(b[e])):
        if b[e][i] not in f:
            dq.append(b[e][i])
g=[]
for i in f:
    if i not in g:
        g.append(i)
print(len(g)-1)


