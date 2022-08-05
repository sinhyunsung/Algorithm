from collections import deque

a=int(input())

for i in range(a):
    
    b,c=map(int,input().split())    
    dq=deque(list(map(int,input().split())))
    count=0
    while True:    
        max_n=max(dq)
        pop_n=dq.popleft()
        if max_n==pop_n:
            b-=1
            c-=1
            count+=1
            if c==-1:
                break
            
        else:
            dq.append(pop_n)
            c-=1
        if c<0:
            c=b-1
    
    print(count)
        