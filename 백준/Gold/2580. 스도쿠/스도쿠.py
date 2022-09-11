a=[]

for i in range(9):
    a.append(list(map(int,input().split())))

b=[]

for i in range(9):
    for j in range(9):
        if a[i][j]==0:
            b.append([i,j])


def ft(x,y,num):
    global a
    
    for i in range(9):
        if num==a[y][i]:
            return False
        if num==a[i][x]:
            return False
    
    for i in range(3):
        for j in range(3):
            if num==a[(y//3)*3+i][(x//3)*3+j]:
                return False
    return True

def sd(depth):
    global a,b
    if depth==len(b):
        for i in range(9):
            for j in range(9):
                print(a[i][j],end=' ')
            print()
    else:
        for i in range(1,10):
            if ft(b[depth][1],b[depth][0],i):
                a[b[depth][0]][b[depth][1]]=i
                sd(depth+1)
                if 0 in a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]:
                    a[b[depth][0]][b[depth][1]]=0
sd(0)