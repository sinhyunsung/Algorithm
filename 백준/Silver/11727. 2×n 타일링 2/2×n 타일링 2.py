import sys
from collections import deque

n=int(sys.stdin.readline().strip())

l=[0 for i in range(n)]

for i in range(n):
    if i==0:
        l[i]=1
    elif i==1:
        l[i]=3
    else:
        l[i]=l[i-1]*1+l[i-2]*2

print(l[-1]%10007)