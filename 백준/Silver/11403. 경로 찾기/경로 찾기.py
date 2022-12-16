import sys
from collections import deque

n=int(sys.stdin.readline().strip())

l=[]

for i in range(n):
    l.append(list(map(int,sys.stdin.readline().split())))

for i in range(n):
    for y in range(n):
        for x in range(n):
            if l[y][i]==1 and l[i][x]==1:
                l[y][x]=1

for i in range(n):
    for j in l[i]:
        print(j,end=" ")
    print()

