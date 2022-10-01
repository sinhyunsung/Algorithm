
a=int(input())
sumV=0
while a>0:
    if a%5==0:
        break
    a=a-3
    sumV+=1
sumV+=a//5
a=a%5
if a==0:
    print(sumV)
else:
    print(-1)
