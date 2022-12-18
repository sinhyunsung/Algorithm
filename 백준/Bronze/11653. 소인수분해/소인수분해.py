a=int(input())
n=a
b=2
while a!=1:
    for i in range(b,n+1):
        if a%i==0:
            print(i)
            a=int(a//i)
            b=i
            break