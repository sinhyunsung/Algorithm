a=int(input())
b=int(input())
c=int(input())
d=a*b*c
e=[0 for i in range(10)]
while d!=0:
    f=d%10
    e[f]+=1
    d=int(d/10)
for i in range(len(e)):
    print(e[i])

