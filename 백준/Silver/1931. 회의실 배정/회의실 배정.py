a=int(input())
b=[]
for i in range(a):
    b.append(list(map(int,input().split())))

b.sort(key=lambda x:x[0])
b.sort(key=lambda x:x[1])

index=0
count=0


for i in b:
    if i[0]>=index:
        index=i[1]
        count+=1

print(count)