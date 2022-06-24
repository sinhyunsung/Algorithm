a=int(input())
b=[]
for i in range(a):
    c=input()
    if [len(c),c] not in b:
        b.append([len(c),c])

b.sort()

for i in b:
    print(i[1])