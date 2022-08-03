import sys

l=[-1]

def heapify(idx):
    max=len(l)
    left=idx*2
    right=idx*2+1
    small=idx
    if left<max and l[left]<l[small]:
        small=left
    if right < max and l[right] < l[small]:
        small = right
    if small!=idx:
        temp=l[small]
        l[small]=l[idx]
        l[idx]=temp
        heapify(small)

def append(x):
    l.append(x)
    a=len(l)-1
    while(a>0):
        heapify(a)
        a=a//2

n=int(sys.stdin.readline().strip())
for i in range(n):
    m=int(sys.stdin.readline().strip())
    if m==0:
        if len(l)==1:
            print(0)
        else:
            print(l[1])
            l[1]=l[-1]
            l.pop(-1)
            heapify(1)
    else:
        append(m)