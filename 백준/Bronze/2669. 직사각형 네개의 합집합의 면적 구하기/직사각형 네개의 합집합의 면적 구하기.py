a=[list(map(int,input().split())) for i in range(4)]

b=set()

for i in a:
    for x in range(i[0],i[2]):
        for y in range(i[1],i[3]):
            b.add(str(x)+","+str(y))

print(len(b))

