a=int(input())

b=[10000]*(a+1)
b[a]=0

for i in range(a-1,0,-1):
    if len(b)-1>=i*3:
        b[i]=min(b[i+1]+1,b[i*3]+1,b[i*2]+1)
    elif len(b)-1>=i*2:
        b[i]=min(b[i+1]+1,b[i*2]+1)
    else:
        b[i]=b[i+1]+1
        
print(b[1])