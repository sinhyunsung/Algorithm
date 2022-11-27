import sys

q=[]

n=int(sys.stdin.readline())

for i in range(n):
    a=sys.stdin.readline().split()
    if a[0]=='push_back':
        q.append(int(a[1]))
    if a[0]=='push_front':
        q=[a[1]]+q
    elif a[0]=="pop_front":
        if len(q)>0:
            print(q[0])
            q=q[1:]
        else:
            print(-1)
    elif a[0]=="pop_back":
        if len(q)>0:
            print(q[-1])
            q=q[:-1]
        else:
            print(-1)
    elif a[0]=='size':
        print(len(q))
    elif a[0]=='empty':
        if len(q)==0:
            print(1)
        else:
            print(0)
    elif a[0]=="front":
        if len(q)>0:
            print(q[0])
        else:
            print(-1)
    elif a[0]=="back":
        if len(q)>0:
            print(q[len(q)-1])
        else:
            print(-1)
