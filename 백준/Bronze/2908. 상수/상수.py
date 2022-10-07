
a=input().split()
b=[]

b.append(a[0][2]+a[0][1]+a[0][0])
b.append(a[1][2]+a[1][1]+a[1][0])

if int(b[0])>int(b[1]):
    print(b[0])
else:
    print(b[1])
