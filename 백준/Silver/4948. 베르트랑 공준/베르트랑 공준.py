def isPrime(n):
    for i in range(n*2,250000,n):
        yield i
arr=[1]*250000
arr[1]=0
for i in range(2,250000):
    if arr[i]==0:
        continue
    for j in isPrime(i):
        arr[j]=0


indata=int(input())
while indata!=0:
    sumv=0
    for i in range(indata+1,(indata*2)+1):
        if arr[i]==1:
            sumv+=1
    print(sumv)
    indata=int(input())



