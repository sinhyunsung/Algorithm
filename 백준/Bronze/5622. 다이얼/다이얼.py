
a=[3+int((i/3)) for i in range(24)]
a.insert(16,8)
a.insert(25,10)
sumV=0
b=input()
for i in range(len(b)):
    sumV+=a[ord(b[i])-65]
    
print(sumV)