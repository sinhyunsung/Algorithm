import sys

n=int(sys.stdin.readline().strip())

l = [0 for i in range(12)]
for j in range(1, 12):
    if j==1:
        l[j]=1
    elif j==2:
        l[j]=2
    elif j==3:
        l[j]=4
    else:
        l[j]=l[j-3]+l[j-2]+l[j-1]


for i in range(n):
    c=int(sys.stdin.readline().strip())
    print(l[c])
