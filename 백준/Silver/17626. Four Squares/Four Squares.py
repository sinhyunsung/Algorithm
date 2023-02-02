import sys
from collections import deque
import math

n=int(sys.stdin.readline())

result=4


for i in range(1,int(math.sqrt(n))+1):
    for j in range(1, int(math.sqrt(n-i**2))+1):
        if math.sqrt(n-i**2-j**2)==int(math.sqrt(n-i**2-j**2)):
            result=3
            break

for i in range(1,int(math.sqrt(n))+1):
    if math.sqrt(n-i**2)==int(math.sqrt(n-i**2)):
        result=2
        break

if math.sqrt(n)==int(math.sqrt(n)):
    result=1
    
print(result)

