import sys
from collections import deque


def permutation(lst,depth,startdepth):
    if depth==7:
        global result
        if abs(sum(lst)-target)+7-startdepth<result:
            result=abs(sum(lst)-target)+7-startdepth
    else:
        for i in l:
            lst.append(i*(10**(6-depth)))
            permutation(lst,depth+1,startdepth)
            lst.pop()


target=int(sys.stdin.readline().strip())
n=int(sys.stdin.readline().strip())

l=[0,1,2,3,4,5,6,7,8,9]
if n>0:
    n=list(map(int,sys.stdin.readline().strip().split()))

    for i in n:
        l.remove(i)

result=abs(target-100)

tmp=[]

permutation(tmp,1,1)
permutation(tmp,2,2)
permutation(tmp,3,3)
permutation(tmp,4,4)
permutation(tmp,5,5)
permutation(tmp,6,6)

print(result)
