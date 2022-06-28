

a=int(input())
sumv=0
plus=1
while a>sumv:
    sumv+=plus
    plus+=1

if plus%2==0:
    print('%d/%d'%((1+(sumv-a)),(plus-(sumv-a)-1)))
else:
    print('%d/%d'%((plus-(sumv-a)-1),(1+(sumv-a))))