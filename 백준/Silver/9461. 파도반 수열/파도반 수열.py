
a=int(input())
c=[1,1,1]+[0]*97
for i in range(97):
    c[i+3]=c[i]+c[i+1]
for i in range(a):
    b=int(input())
    print(c[b-1])