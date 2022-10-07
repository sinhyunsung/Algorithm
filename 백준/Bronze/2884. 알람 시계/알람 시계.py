a=input().split()
a[0]=int(a[0])
a[1]=int(a[1])

if a[1]>=45:
    a[1]-=45
else:
    a[0]-=1
    if a[0]<0:
        a[0]=23
    a[1]=60-45+a[1]
print(a[0],a[1])