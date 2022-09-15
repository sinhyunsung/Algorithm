a=int(input())

def logic(f,b):
    v=2
    while(b>=0):
        tmp=b
        b=f-b
        f=tmp
        if b>=0:
            v+=1
    return v

maxn=0
maxb=0

for i in range(1,a+1):
    result=logic(a,i)
    if result>maxn:
        maxn=result
        maxb=i


print(maxn)
print(a,end=" ")
print(maxb,end=" ")

while(maxb>=0):
    tmp=maxb
    maxb=a-maxb
    a=tmp
    if maxb>=0:
        print(maxb,end=" ")