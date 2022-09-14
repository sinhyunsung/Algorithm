a,b=map(int,input().split())

if b>a:
    tmp=a
    a=b
    b=tmp

for i in range(b,0,-1):
    if a%i==0 and b%i==0:
        x=i
        break

y=int((a*b)/x)
print(x)
print(y)