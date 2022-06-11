

def innum(num):
    a=str(num)
    b=[]
    for i in range(len(a)):
        b.append(int(a[i]))
    if len(b)>2:
        if (b[0]-b[1])==(b[1]-b[2]):
            return True
        else:
            return False
    else:
        return True
inp=int(input())
sum=0
for j in range(1,inp+1):
    if innum(j):
        sum+=1

print(sum)