
a=int(input())

sumV=0
for i in range(a):
    b=input()
    now_alpha='?'
    alpha=[0 for i in range(26)]
    for j in range(len(b)):
        if alpha[ord(b[j])-97]==1 and now_alpha!=b[j]:
            break
        else:
            now_alpha=b[j]
            alpha[ord(b[j])-97]=1
    else:
        sumV+=1
print(sumV)
        