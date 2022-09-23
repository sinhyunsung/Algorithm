a=[0,1]

for i in range(89):
    a.append(a[i]+a[i+1])

b=int(input())
print(a[b])