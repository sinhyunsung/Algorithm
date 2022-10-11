import math

a=int(input())
b=[]

for i in range(a):
    b.append(int(input()))

b.sort()

for i in range(a-1):
    b[i]=abs(b[i]-b[i+1])
b.pop(a-1)

if len(b)>1:
    gcd=[]
    
    for i in range(len(b)-1):
        gcd.append(math.gcd(b[i],b[i+1]))
    
    while len(gcd)!=1:
        gcd2=[]
        for i in range(len(gcd)-1):
            gcd2.append(math.gcd(gcd[i],gcd[i+1]))
        else:
            gcd=gcd2
    
else:
    gcd=b

x=[]
for i in range(2,int(math.sqrt(gcd[0]))+1):
    if gcd[0]%i==0:
        print(i,end=' ')
        x.append(i)
x.sort(reverse=True)
for i in x:
    if gcd[0]//i not in x:
        print(gcd[0]//i,end=' ') 

print(gcd[0])