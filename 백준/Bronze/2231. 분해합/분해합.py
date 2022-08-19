a=int(input())

for i in range(a):
    sumv=i
    b=i
    while b!=0:
        sumv+=int(b%10)
        b=int(b//10)
    if sumv==a:
        print(i)
        break
else:
    print(0)