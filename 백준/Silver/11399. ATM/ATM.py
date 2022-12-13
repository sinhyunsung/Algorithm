a=int(input())
b=list(map(int,input().split()))
b.sort()
sumv=0
for i in range(a):
    for j in range(0,i+1):
        sumv+=b[j]
        
print(sumv)