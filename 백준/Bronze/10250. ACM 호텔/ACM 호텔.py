a=int(input())

for i in range(a):
    b=list(map(int,input().split()))
    H=0
    ho=1
    while b[2]>0:
        if H==b[0]:
            H=1
            ho+=1
        else:
            H+=1
        b[2]-=1
       
    if ho<10:
        print(str(H)+'0'+str(ho))
    else:
        print(str(H)+str(ho))