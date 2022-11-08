a= int(input())

for i in range(a):
    
    b=int(input())
    c=[]
    
    for j in range(b):
        d=input().split()
        c.append(d[1])
    d=set(c)
    v=1
    for j in d:
        v*=c.count(j)+1
    print(v-1)
        