a=[]
for i in range(10):
    a.append(int(input())%42)
a=list(set(a))
print(len(a))