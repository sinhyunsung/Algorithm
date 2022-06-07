import sys
from collections import deque
import math

n,m=map(int,sys.stdin.readline().split())

l=[i for i in range(n+1)]


def find(x):
    if l[x]==x:
        return x
    else:
        l[x]=find(l[x])
        return l[x]

h=sys.stdin.readline().strip()
if h=="0":
    None
else:
    h=list(map(int,h.split()))
    pl=[]
    for _ in range(m):
        p=list(map(int,sys.stdin.readline().split()))
        pl.append(p[1:])
        if p[0]==1:
            continue
        else:
            for i in range(2,p[0]+1):
                a=find(p[i])
                b=find(p[i-1])
                if a>b:
                    l[a]=b
                else:
                    l[b]=a
    for i in range(1,n+1):
        find(i)
    h[0]=h[1]

    for i in range(len(h)):
        h[i]=l[h[i]]

    for i in range(m):
        for j in pl[i]:
            if l[j] in h:
                m-=1
                break

print(m)
