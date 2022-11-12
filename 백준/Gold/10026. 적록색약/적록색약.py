import sys
from collections import deque
import copy

n=int(sys.stdin.readline().strip())

l=[]
for i in range(n):
    l.append(list(sys.stdin.readline().strip()))

temp=copy.deepcopy(l)

bfs=deque()

next_bfs=deque()

dx=[0,0,1,-1]
dy=[1,-1,0,0]

count1=0
count2=0
next_bfs.append([0,0])

while(next_bfs):
    next_y,next_x=next_bfs.popleft()
    bfs.append([next_y,next_x,l[next_y][next_x]])

    if l[next_y][next_x]!="X":
        count1+=1
        l[next_y][next_x]="X"
    else:
        bfs.pop()
        continue
    while(bfs):
        y,x,now_col=bfs.popleft()



        for i in range(4):
            x_=x+dx[i]
            y_=y+dy[i]
            if x_>=0 and x_<n and y_>=0 and y_<n and l[y_][x_]!="X":
                if now_col==l[y_][x_]:
                    bfs.append([y_,x_,l[y_][x_]])
                    l[y_][x_]="X"
                else:
                    next_bfs.append([y_, x_])

l=temp

for i in range(n):
    for j in range(n):
        if l[i][j]=="R":
            l[i][j]="G"


next_bfs.append([0,0])

while(next_bfs):
    next_y,next_x=next_bfs.popleft()
    bfs.append([next_y,next_x,l[next_y][next_x]])

    if l[next_y][next_x]!="X":
        count2+=1
        l[next_y][next_x]="X"
    else:
        bfs.pop()
        continue
    while(bfs):
        y,x,now_col=bfs.popleft()



        for i in range(4):
            x_=x+dx[i]
            y_=y+dy[i]
            if x_>=0 and x_<n and y_>=0 and y_<n and l[y_][x_]!="X":
                if now_col==l[y_][x_]:
                    bfs.append([y_,x_,l[y_][x_]])
                    l[y_][x_]="X"
                else:
                    next_bfs.append([y_, x_])

print(count1,count2)