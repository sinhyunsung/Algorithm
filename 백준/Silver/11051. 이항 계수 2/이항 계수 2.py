def f(n):
    re=1
    for i in range(2,n+1):
        re*=i
    return re

a,b=map(int,input().split())
print(f(a)//f(b)//f(a-b)%10007)