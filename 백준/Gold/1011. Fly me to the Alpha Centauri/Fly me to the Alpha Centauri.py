
a=int(input())

for i in range(a):
    b=list(map(int,input().split()))
    c=pow(b[1]-b[0],1/2)*2-1
    if c%1==0:
        print(int(c))
    else:
        print(int(c)+1)