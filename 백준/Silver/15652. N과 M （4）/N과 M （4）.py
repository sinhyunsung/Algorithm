a=list(map(int,input().split()))

result=[0]*a[1]

def fun(depth,m,n,t):
    global result
    
    if depth==(n):
        for i in range(len(result)):
            print(result[i],end=' ')
        print()
    else:
        for i in range(t,m+1):
            result[depth]=i
            if t<i:
                t=i
            fun(depth+1,m,n,t)

fun(0,a[0],a[1],1)