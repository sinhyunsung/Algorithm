
    
    
a=[0 for i in range(26)]
b=input().lower()

for i in range(len(b)-1,-1,-1):
    a[ord(b[i])-97]+=1
if a.count(a[a.index(max(a))])==1:
    print(chr(a.index(max(a))+65))
else:
    print('?')