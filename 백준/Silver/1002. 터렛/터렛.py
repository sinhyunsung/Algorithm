import math

a=int(input())

for i in range(a):
    b=list(map(int,input().split()))
    c=math.sqrt(pow(b[0]-b[3],2)+pow(b[1]-b[4],2))
    if b[0]==b[3] and b[1]==b[4] and b[2]==b[5]:
        print(-1)
    elif c==b[2]+b[5] or c==abs(b[2]-b[5]):
        print(1)
    elif c<b[2]+b[5] and c>abs(b[2]-b[5]):
        print(2)
    else:
        print(0)