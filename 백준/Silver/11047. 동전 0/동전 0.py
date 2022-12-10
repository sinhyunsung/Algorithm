a,b=map(int,input().split())
c=[]
d=0
for i in range(a):
    c.append(int(input()))
c.sort(reverse=True)
for i in c:
    d+=int(b//i)
    b=int(b%i)
print(d)