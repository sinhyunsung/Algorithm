a,b=map(int,input().split())

c=[i+1 for i in range(a)]
d=[False for i in range(a)]
e=[0 for i in range(b)]

def print_num(tmp,a,b):
    if tmp==b:
        for i in e:
            print(i,end=' ')
        print()
        return
    else:
        for i in range(a):
            if d[i]==False:
                e[tmp]=c[i]
                d[i]=True
                print_num(tmp+1,a,b)
                d[i]=False
            else:
                continue

print_num(0,a,b)