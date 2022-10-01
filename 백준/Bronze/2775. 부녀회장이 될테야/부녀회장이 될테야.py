
a=int(input())
b=[[0 for i in range(14)] for i in range(15)]
for i in range(15):
    for j in range(14):
        if i==0:
            b[i][j]=j+1
        else:
            for k in range(j+1):
                b[i][j]+=b[i-1][k]
for i in range(a):
    c=int(input())
    d=int(input())
    print(b[c][d-1])