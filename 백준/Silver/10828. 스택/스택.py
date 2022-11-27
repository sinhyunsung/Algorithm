import sys

a=int(sys.stdin.readline())

stack=[]
for i in range(a):
    b=sys.stdin.readline().split()
    
    if b[0]=='push':
        stack.append(int(b[1]))
    elif b[0]=='pop':
        if len(stack)==0:
            print(-1)
        else:
            print(stack[len(stack)-1])
            stack.pop(len(stack)-1)
    elif b[0]=='size':
        print(len(stack))
    elif b[0]=='empty':
        if len(stack)==0:
            print(1)
        else:
            print(0)
    else:
        if len(stack)==0:
            print(-1)
        else:
            print(stack[len(stack)-1])