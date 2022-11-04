def isPrime(n):
    for i in range(n*2,10001,n):
        yield i
arr=[1]*10001
arr[1]=0
for i in range(2,10001):
    if arr[i]==0:
        continue
    for j in isPrime(i):
        arr[j]=0

a=int(input())

for i in range(a):
    b=int(input())
    for j in range(int(b/2),1,-1):
        if arr[j]==1 and arr[b-j]==1:
            print(j,b-j)
            break


