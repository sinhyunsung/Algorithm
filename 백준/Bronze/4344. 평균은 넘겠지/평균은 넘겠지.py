a=int(input())

for i in range(a):
    b=list(map(int,input().split()))
    c=b[0]
    b.pop(0)
    d=sum(b)/c
    e=0
    for i in b:
        if i>d:
            e+=1
    print('%.3f%%'%round((e/c*100),3))