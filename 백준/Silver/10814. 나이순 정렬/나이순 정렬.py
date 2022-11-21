a=int(input())
b=[]
for i in range(a):
    c,d=input().split()
    b.append([int(c),i,d])

b.sort(reverse=False)

for i in b:
    print(i[0],i[2])