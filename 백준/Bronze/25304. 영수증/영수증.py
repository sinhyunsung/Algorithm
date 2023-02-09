import sys
from collections import deque
import math

n=int(sys.stdin.readline().strip())
m=int(sys.stdin.readline().strip())
sum=0
for i in range(m):
    a,b=map(int,sys.stdin.readline().split())
    sum+=a*b
if sum==n:
    print("Yes")
else:
    print("No")