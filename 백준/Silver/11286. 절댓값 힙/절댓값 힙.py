import sys
from collections import deque

l=[-1]

n=int(sys.stdin.readline().strip())

for i in range(n):
    x=int(sys.stdin.readline().strip())

    if x==0:
        if len(l)>1:
            print(l[1])
            temp=l[1]
            l[1]=l[-1]
            l[-1]=temp
            l.pop()

            idx=1
            while(idx<len(l)):
                left=idx*2
                right=idx*2+1
                target=idx
                if left<len(l) and abs(l[left]) < abs(l[target]):
                    target=left
                if right<len(l) and abs(l[right]) < abs(l[target]):
                    target=right
                if left < len(l) and abs(l[left]) == abs(l[target]) and l[left]<l[target]:
                    target = left
                if right < len(l) and abs(l[right]) == abs(l[target])and l[right]<l[target]:
                    target = right
                if target!=idx:
                    temp=l[idx]
                    l[idx]=l[target]
                    l[target]=temp
                    idx=target
                else:
                    break
        else:
            print(0)
    else:
        l.append(x)
        idx=len(l)-1
        while(idx>1):
            target=idx//2
            if (abs(l[idx])<abs(l[target])) or (l[idx]<l[target] and abs(l[idx]) == abs(l[target])):
                temp=l[idx]
                l[idx]=l[target]
                l[target]=temp
                idx=target
            else:
                break


