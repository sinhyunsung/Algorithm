
a=[-1 for i in range(26)]
b=input()
for i in range(len(b)-1,-1,-1):
    a[ord(b[i])-97]=i
for i in range(len(a)):
    print(a[i],end=' ')