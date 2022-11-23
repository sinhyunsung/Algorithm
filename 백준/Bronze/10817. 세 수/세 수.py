
a=input().split()
a[0]=int(a[0])
a[1]=int(a[1])
a[2]=int(a[2])

if (a[0]>=a[1] and a[1]>=a[2]) or (a[2]>=a[1] and a[1]>=a[0]):
    print(a[1])
elif (a[0]>=a[2] and a[2]>=a[1]) or (a[1]>=a[2] and a[2]>=a[0]):
    print(a[2])
else:
    print(a[0])