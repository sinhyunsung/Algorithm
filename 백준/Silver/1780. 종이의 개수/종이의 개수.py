import sys
from collections import deque

n=int(sys.stdin.readline().strip())

l=[]

for i in range(n):
    l.append(list(map(int,sys.stdin.readline().split())))

result=[0,0,0]

def check(sx,sy,size):
    v=100
    for i in range(sx,sx+size):
        for j in range(sy, sy + size):
            if v==100:
                v=l[i][j]
            else:
                if v!=l[i][j]:
                    for a in range(sx,sx+size,size//3):
                        for b in range(sy, sy+size,size//3):
                            check(a,b,size//3)
                    return
    result[v+1]+=1

check(0,0,n)
print(result[0])
print(result[1])
print(result[2])