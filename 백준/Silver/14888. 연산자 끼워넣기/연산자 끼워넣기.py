a=int(input())
b=list(map(int,input().split()))
c=list(map(int,input().split()))
d=[]
for i in range(c[0]):
    d.append('+')
for i in range(c[1]):
    d.append('-')
for i in range(c[2]):
    d.append('*')
for i in range(c[3]):
    d.append('/')

e=[True for i in range(sum(c))]

minv=1000000000
maxv=-1000000000

do=b[0]

def oper(depth):
    global do,minv,maxv,d,c,e
    if do>1000000000:
        do=1000000000
    elif do<-1000000000:
        do=-1000000000
        
    if depth==sum(c):
        if do<minv:
            minv=do
        if do>maxv:
            maxv=do
    else:
        for i in range(len(d)):
            if e[i]:
                if d[i]=='+':
                    doback=do
                    do=(do+b[depth+1])
                    e[i]=False
                    oper(depth+1)
                    do=doback
                    e[i]=True
                elif d[i]=='-':
                    doback=do
                    do=(do-b[depth+1])
                    e[i]=False
                    oper(depth+1)
                    do=doback
                    e[i]=True
                elif d[i]=='*':
                    doback=do
                    do=(do*b[depth+1])
                    e[i]=False
                    oper(depth+1)
                    do=doback
                    e[i]=True
                elif d[i]=='/':
                    doback=do
                    if do<0:    
                        do=-(-do//b[depth+1])
                    else:
                        do=do//b[depth+1]
                    e[i]=False
                    oper(depth+1)
                    do=doback
                    e[i]=True
                
            else:
               continue
                    
oper(0)
print(maxv)
print(minv)        