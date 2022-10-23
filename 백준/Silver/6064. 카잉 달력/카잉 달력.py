import sys
from collections import deque
c=int(sys.stdin.readline().strip())
def GCD(x,y):
    while(y):
        x,y=y,x%y
    return x

def LCM(x,y):
    result = (x*y)//GCD(x,y)
    return result

for i in range(c):

    m, n, x, y = map(int, sys.stdin.readline().split())
    total=LCM(m,n)
    s=1
    a,b=1,1
    a+=x-a
    b=a
    s=a

    while(s<=total):

        if b%n==0:
            b=n
        else:
            b%=n
        if(b==y):
            print(s)
            break
        s+=m
        b=b+m
    else:
        print(-1)


