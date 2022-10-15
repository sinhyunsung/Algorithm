

while True:
    a=input()
    if a=='.':
        break
    
    stack=[]
    
    for i in a:
        try:
            if i=='(':
                stack.append(0)
            elif i=='[':
                stack.append(1)
            elif i==')':
                if stack[len(stack)-1]==0:
                    stack.pop(len(stack)-1)
                else:
                    print('no')
                    break
            elif i==']':
                if stack[len(stack)-1]==1:
                    stack.pop(len(stack)-1)
                else:
                    print('no')
                    break
            else:
                continue
        except:
            print('no')
            break
    else:
        if len(stack)==0:
            print('yes')
        else:
            print('no')
