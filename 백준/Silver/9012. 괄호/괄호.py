a=int(input())

for i in range(a):
    b=input()
    stack=0
    for j in b:
        if j=='(':
            stack+=1
        else:
            stack-=1
        if stack<0:
            break
    if stack==0:
        print('YES')
    else:
        print('NO')