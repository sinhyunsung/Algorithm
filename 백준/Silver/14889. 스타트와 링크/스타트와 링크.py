a=int(input())
b=[list(map(int,input().split())) for i in range(a)]

c=[True for i in range(a)]
d=[]

minv=100000

def score(li):
    global b
    score=0
    for i in li:
        for j in li:
            score+=b[i][j]
    return score

def bt(dep,idx):
    global a,c,d,minv
    if dep==(a//2):
        t1=[]
        t2=[]
        for i in range(len(c)):
            if c[i]:
                t1.append(i)
            else:
                t2.append(i)
        v=abs(score(t1)-score(t2))
        if minv > v:
            minv=v
        return
    else:
        for i in range(idx,a):
            if c[i]:
                c[i]=False
                bt(dep+1,i)
                c[i]=True
            else:
                continue

bt(0,0)
print(minv)