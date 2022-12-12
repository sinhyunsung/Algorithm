import sys
from collections import deque

l=[-1]

n=int(sys.stdin.readline().strip())
for i in range(n):
    a = int(sys.stdin.readline().strip())
    if a==0:
        if len(l)>1:
            print(l[1])
            x=len(l)-1
            temp=l[x]
            l[x]=l[1]
            l[1]=temp
            l.pop()
            idx=1
            while(1):
                left=idx*2
                right=idx*2+1
                target=idx
                if left<len(l) and l[left]>l[target]:
                    target=left
                if right<len(l) and l[right]>l[target]:
                    target=right
                if idx!=target:
                    temp = l[idx]
                    l[idx] = l[target]
                    l[target] = temp
                    idx=target
                    continue
                break

        else:
            print(0)
    else:
        if len(l)>1:
            l.append(a)
            x=len(l)-1
            while(x>1):
                y=x//2
                if l[x]>l[y]:
                    temp=l[x]
                    l[x]=l[y]
                    l[y]=temp
                    x=x//2
                    continue
                break
        else:
            l.append(a)