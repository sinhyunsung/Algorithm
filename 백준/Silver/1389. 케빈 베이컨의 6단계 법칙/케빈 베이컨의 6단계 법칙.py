import sys
from collections import deque

n,m=map(int,sys.stdin.readline().split())

l=[[5001]*(n) for i in range(n)]

for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    l[a-1][b-1]=1
    l[b-1][a-1]=1

for i in range(n):
    for j in range(n):
        for k in range(n):
            if l[j][k]>l[j][i]+l[i][k]:
                l[j][k] = l[j][i] + l[i][k]

min=5001

for i in range(n):
    if min>sum(l[i]):
        min=sum(l[i])
        idx=i

print(idx+1)