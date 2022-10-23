import sys
from collections import deque
x,y,h=map(int,sys.stdin.readline().strip().split())

m=[]
for k in range(h):
    y_map=[]
    for i in range(y):
        y_map.append(list(map(int,sys.stdin.readline().strip().split())))
    m.append(y_map)

bfs=deque()

for _x in range(x):
    for _y in range(y):
        for _h in range(h):
            if m[_h][_y][_x]==1:
                bfs.append([_x,_y,_h,0])

dx=[1,-1,0,0,0,0]
dy=[0,0,1,-1,0,0]
dh=[0,0,0,0,1,-1]

max_d=0
while(bfs):
    _x,_y,_h,_d=bfs.popleft()
    for i in range(6):
        nx = _x + dx[i]
        ny = _y + dy[i]
        nh = _h + dh[i]
        if nx>=0 and nx<x and ny>=0 and ny<y and nh>=0 and nh<h:
            if m[nh][ny][nx]==0:
                bfs.append([nx,ny,nh,_d+1])
                if _d+1>max_d:
                    max_d=_d+1
                m[nh][ny][nx] =1

check=0
for _x in range(x):
    for _y in range(y):
        for _h in range(h):
            if m[_h][_y][_x]==0:
                check=1
                print(-1)
                break
        if check:
            break
    if check:
        break

if check==0:
    print(max_d)



