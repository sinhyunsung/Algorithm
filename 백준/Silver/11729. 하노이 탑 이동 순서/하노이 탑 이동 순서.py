a=int(input())

sumV=0
b=[]

def hanoi(num,stat,temp,target):
    global sumV
    sumV+=1
    if num==1:
        b.append('%d %d'%(stat,target))
    else:
        hanoi(num-1,stat,target,temp)
        b.append('%d %d'%(stat,target))
        hanoi(num-1,temp,stat,target)

hanoi(a,1,2,3)
print(sumV)
for i in range(len(b)):
    print(b[i])