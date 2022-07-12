import sys
from collections import deque

n,m=map(int,sys.stdin.readline().split())

l={}
l2={}

num=1
for i in range(n):
    name=sys.stdin.readline().strip()
    l[name]=num
    l2[str(num)]=name
    num+=1

for i in range(m):
    q = sys.stdin.readline().strip()
    if q.isdigit():
        print(l2[q])
    else:
        print(l[q])