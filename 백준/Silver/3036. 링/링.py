a=int(input())
b=list(map(int,input().split()))

def gcd(x,y):
    while y!=0:
        tmp=x
        x=y
        y=tmp%y
    return x

for i in range(1,a):
    gcdv=gcd(b[0],b[i])
    print(str(b[0]//gcdv)+'/'+str(b[i]//gcdv))