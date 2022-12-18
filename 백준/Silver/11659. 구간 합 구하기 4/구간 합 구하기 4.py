import sys
from collections import deque

n,m=map(int,sys.stdin.readline().split())

l=[0 for i in range(n+1)]

k=list(map(int,sys.stdin.readline().split()))

for i in range(n):
    l[i+1]=l[i]+k[i]

for i in range(m):
    a,b=map(int,sys.stdin.readline().split())
    print(l[b]-l[a-1])


