a=int(input())

queen=[0]*a
sumv=0

def fun(depth,a):
    global queen,sumv
    if depth==a:
        sumv+=1
    else:
        for i in range(1,a+1):
            queen[depth]=i
            if depth==0:
                fun(depth+1,a)
            else:
                for j in range(1,depth+1):
                    if queen[depth-j]==queen[depth] or queen[depth-j]==queen[depth]-j or queen[depth-j]==queen[depth]+j:
                        break
                else:
                    fun(depth+1,a)
            
fun(0,a)
print(sumv)