
a=input().split()
b=input().split()

for i in range(int(a[0])):
    if int(b[i]) < int(a[1]):
        print(b[i],end=' ')
