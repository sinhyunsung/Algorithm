import itertools

binggo=[list(map(int,input().split())) for i in range(5)]

moderator=[list(map(int,input().split())) for i in range(5)]
moderator=list(itertools.chain(*moderator))

def check(li):
    binggo=0
    for i in range(5):
        if sum(li[i])==0:
            binggo+=1
        if sum([li[j][i] for j in range(5)])==0:
            binggo+=1
    if sum([li[i][i] for i in range(5)])==0:
        binggo+=1
    if sum([li[4-i][i] for i in range(5)])==0:
        binggo+=1
    return binggo

result=0

for i in moderator:
    for j in binggo:
        if i in j:
            j[j.index(i)]=0
            result += 1
            break

    if check(binggo)>=3:
        print(result)
        break

