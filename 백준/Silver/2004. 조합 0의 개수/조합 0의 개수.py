a,b=map(int,input().split())

def f(x):
    a=x
    o=0
    c=0
    while a//(5**c)!=0:
        
        c+=1     
        o+=a//(5**c)
       
    e=0
    c=0
    while a//(2**c)!=0:
        c+=1
        e+=a//(2**c)
    return e,o

a1,b1=f(a)
a2,b2=f(b)
a3,b3=f(a-b)
print(min(a1-a2-a3,b1-b2-b3))