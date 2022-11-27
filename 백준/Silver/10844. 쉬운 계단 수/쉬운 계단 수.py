a=int(input())
b=[0,1,1,1,1,1,1,1,1,1]
def fun(b):
    c=[0]*10
    c[0]=(b[1])%1000000000
    for j in range(8):
        c[j+1]=(b[j]+b[j+2])%1000000000
    c[9]=(b[8])%1000000000
    return c

for i in range(a-1):
    b=fun(b)
print((sum(b))%1000000000)
