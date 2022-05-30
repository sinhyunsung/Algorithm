
c=[0,1]
for i in range(89):
    c.append(c[i]+c[i+1])

a=int(input())
for i in range(a):
    b=int(input())
    if b!=0:
        print(c[b-1],c[b])
    else:
        print(1,0)
