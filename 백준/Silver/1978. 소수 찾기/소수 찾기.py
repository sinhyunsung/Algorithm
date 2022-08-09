
input()
a=list(map(int,input().split()))
sumV=0
for i in range(len(a)):
    for j in range(2,a[i]):
        if a[i]%j==0:
            break
    else:
        if a[i]!=1:
            sumV+=1
        
print(sumV)
    