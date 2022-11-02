a=int(input())
for i in range(a):
    b=input()
    c=1
    score=0
    for i in b:
        if i=='O':
            score+=c
            c+=1
        else:
            c=1
    print(score)