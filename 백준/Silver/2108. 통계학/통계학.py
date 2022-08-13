import sys
import math
from collections import Counter

def round_2(num):
    if num%1==0.5:
        return math.ceil(num)
    else:
        return int(round(num,0))

N = int(sys.stdin.readline())
a=[]

for i in range(N):
    a.append(int(sys.stdin.readline()))



result = Counter(a).most_common()
m=result[0][1]
c=[]

for i in range(len(result)):
    if result[i][1]==m:
        c.append(result[i][0])
if len(c)>1:
    c.remove(min(c))


a.sort()
print(round_2(sum(a)/N))
print(a[N//2])
print(min(c))
print(max(a)-min(a))

