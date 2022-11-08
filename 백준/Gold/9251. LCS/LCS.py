
a=input()
b=input()

c=[[0]*(len(a)+1) for i in range(len(b)+1)]

for i in range(len(b)):
    for j in range(len(a)):
        if b[i]==a[j]:
            c[i+1][j+1]=c[i][j]+1
        else:
            c[i+1][j+1]=max(c[i+1][j],c[i][j+1])

print(c[len(b)][len(a)])