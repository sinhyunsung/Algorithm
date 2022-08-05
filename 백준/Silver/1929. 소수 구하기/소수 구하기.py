def isPrime(n):
    for i in range(n*2,1000001,n):
        yield i
arr=[1]*1000001
arr[1]=0
for i in range(2,1000001):
    if arr[i]==0:
        continue
    for j in isPrime(i):
        arr[j]=0
n,m=map(int,input().split())
for i in range(n,m+1):
    if arr[i]==1:
        print(i)