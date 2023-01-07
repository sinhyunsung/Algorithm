import sys
from collections import deque

y,x=map(int,sys.stdin.readline().split())
l=[]
for i in range(y):
    l.append(list(map(int,sys.stdin.readline().split())))

sum=0

dx=[0,0,1,-1]
dy=[1,-1,0,0]

l2=[[0]*x for i in range(y)]

for i in range(y):
    for j in range(x):

        if j+2<x and i+1<y:
            now=l[i][j]+l[i][j+1]+l[i][j+2]+l[i+1][j+1]
            if sum<now:
                sum=now
        if j+2<x and i-1>=0:
            now=l[i][j]+l[i][j+1]+l[i][j+2]+l[i-1][j+1]
            if sum<now:
                sum=now
        if j+1<x and i+2<y:
            now=l[i][j]+l[i+1][j]+l[i+2][j]+l[i+1][j+1]
            if sum<now:
                sum=now
        if j-1>=0 and i+2<y:
            now=l[i][j]+l[i+1][j]+l[i+2][j]+l[i+1][j-1]
            if sum<now:
                sum=now

        now=l[i][j]

        for mv1 in range(4):
            ax=j+dx[mv1]
            ay=i+dy[mv1]
            if ax >=0 and ax < x and ay>=0 and ay<y:
                now+=l[ay][ax]
            else:
                continue
            for mv2 in range(4):
                if (mv1!=2 or mv2!=1) and (mv1!=1 or mv2!=2) and (abs(mv1-mv2)==1) :
                    continue
                bx = ax + dx[mv2]
                by = ay + dy[mv2]
                if bx >= 0 and bx < x and by >= 0 and by < y:
                    now += l[by][bx]
                else:
                    continue
                for mv3 in range(4):

                    if (mv3!=2 or mv2!=1) and (mv3 != 1 or mv2 != 2) and (abs(mv3 - mv2) == 1):
                        continue
                    cx = bx + dx[mv3]
                    cy = by + dy[mv3]
                    if cx >= 0 and cx < x and cy >= 0 and cy < y and l2[cy][cx]!=-1:
                        now += l[cy][cx]
                    else:
                        continue
                    if sum<now:
                        sum=now
                    now-=l[cy][cx]
                now -= l[by][bx]
            now -= l[ay][ax]
        l2[i][j]=-1

print(sum)