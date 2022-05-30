import sys
from collections import deque

n=int(sys.stdin.readline().strip())

for k in range(n):
    count=0

    x1,y1,x2,y2=map(int,sys.stdin.readline().split())

    m=int(sys.stdin.readline().strip())

    for i in range(m):
        x3,y3,r=map(int,sys.stdin.readline().split())
        if ((x1-x3)**2+(y1-y3)**2<r**2 and (x2-x3)**2+(y2-y3)**2>r**2) or ((x1-x3)**2+(y1-y3)**2>r**2 and (x2-x3)**2+(y2-y3)**2<r**2):
            count+=1

    print(count)
