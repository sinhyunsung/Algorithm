a=input().split('-')

pv=list(map(int,a[0].split('+')))
mv=[]

sumv=0
for i in range(1,len(a)):
    mv+=list(map(int,a[i].split('+')))

for i in pv:
    sumv+=i
for i in mv:
    sumv-=i



print(sumv)
