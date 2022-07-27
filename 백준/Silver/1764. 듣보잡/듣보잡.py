import sys

m,n=map(int,sys.stdin.readline().split())
dic={}
l=[]

for i in range(m):
    dic[sys.stdin.readline().strip()]=1

for i in range(n):
    name=sys.stdin.readline().strip()
    if name in dic:
        l.append(name)

l.sort()

print(len(l))
for i in l:
    print(i)