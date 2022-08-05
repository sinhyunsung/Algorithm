
a=int(input())

for i in range(a):
    b=list(map(int,input().split()))
    if i==0:
        c=[b[i] for i in range(len(b))]
    else:
        for j in range(i+1):
            if j==0:
                b[j]+=c[j]
            elif j==i:
                b[j]+=c[j-1]
            else:
                if c[j-1]>c[j]:
                    b[j]+=c[j-1]
                else:
                    b[j]+=c[j]
        c=[b[i] for i in range(len(b))]
print(max(c))