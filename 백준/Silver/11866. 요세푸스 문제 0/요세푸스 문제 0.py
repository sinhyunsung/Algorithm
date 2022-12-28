from collections import deque

a,b=map(int,input().split())

dq=deque([i for i in range(1,a+1)])

li=[]

while len(dq)!=0:
    for i in range(b-1):
        dq.append(dq.popleft())
    else:
        li.append(dq.popleft())

print('<',end='')
for i in range(len(li)):
    if i==len(li)-1:
        print(li[i],end='')
    else:
        print(li[i],end=', ')
print('>',end='')
    
