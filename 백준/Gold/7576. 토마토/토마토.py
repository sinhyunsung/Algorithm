
import sys
import collections

n = list(map(int, sys.stdin.readline().split()))
b = [list(map(int, sys.stdin.readline().split())) for i in range(n[1])]


def day1(qlist):
    global day
    global b
    cqlist=collections.deque()
    while len(qlist)!=0:
        tmp=qlist.popleft()
        if tmp[0]>0 and b[tmp[0]-1][tmp[1]]==0:
            cqlist.append([tmp[0]-1,tmp[1]])
            b[tmp[0]-1][tmp[1]]=1
        if tmp[1]>0 and b[tmp[0]][tmp[1]-1]==0:
            cqlist.append([tmp[0],tmp[1]-1])
            b[tmp[0]][tmp[1]-1]=1
        if tmp[0]<n[1]-1 and b[tmp[0]+1][tmp[1]]==0:
            cqlist.append([tmp[0]+1,tmp[1]])
            b[tmp[0]+1][tmp[1]]=1
        if tmp[1]<n[0]-1 and b[tmp[0]][tmp[1]+1]==0:
            cqlist.append([tmp[0],tmp[1]+1])
            b[tmp[0]][tmp[1]+1]=1
    day+=1
    return cqlist


c=[]
day=0


for i in range(n[1]):
    for j in range(n[0]):
        if b[i][j]==1:
            c.append([i,j])
cqlist=collections.deque()
if(len(c)!=0):
    for i in range(len(c)):
        cqlist.append(c[i])
    
    while(len(cqlist)!=0):
        cqlist=day1(cqlist)
    
for i in range(len(b)):
    if 0 in b[i]:
        print(-1)
        break
else:
    print(day-1)