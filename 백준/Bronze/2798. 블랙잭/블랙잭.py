a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=[]
for i in range(a[0]-2):
    for j in range(a[0]-1):
        for k in range(a[0]):
            if b[i]+b[j]+b[k] <= a[1] and i!=j and j!=k and k!=i:
                c.append(b[i]+b[j]+b[k])

print(max(c))

    