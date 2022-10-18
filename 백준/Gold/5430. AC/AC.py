import sys
from collections import deque

n=int(sys.stdin.readline().strip())

for _ in range(n):
    c=sys.stdin.readline().strip()
    leng=int(sys.stdin.readline().strip())
    if leng>0:
        l=deque(map(int,sys.stdin.readline().strip()[1: -1].split(',')))
    else:
        l=sys.stdin.readline()
        l = deque()
    forward=True
    error=False
    for i in c:
        if i=='D' and len(l)==0:
            error=True
        elif i=='D' and forward:
            l.popleft()
        elif i=='D':
            l.pop()
        else:
            forward=forward^1
    if error:
        print("error")
    elif forward:
        print("[",end="")
        for i in range(len(l)):
            print(l[i],end="")
            if i!=len(l)-1:
                print(",",end="")
        print("]")
    else:
        print("[",end="")
        for i in range(len(l)):
            print(l[len(l)-1-i],end="")
            if i!=len(l)-1:
                print(",",end="")
        print("]")

