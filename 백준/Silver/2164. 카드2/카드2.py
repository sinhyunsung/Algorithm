from collections import deque

a=int(input())

dq=deque([i for i in range(1,a+1)])

while len(dq)!=1:
    dq.popleft()
    dq.append(dq.popleft())
    
print(dq.pop())
    

