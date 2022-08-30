n=int(input())
side=[]
for i in range(6):
    side.append(list(map(int,input().split())))

len=[0,0,0,0]

result=0
flag=0

for idx,i in enumerate(side):
    len[i[0]-1]+=i[1]
    if side[idx][0]==side[idx-2][0] and side[idx-1][0]==side[idx-3][0]:
        result-=side[idx-2][1]*side[idx-1][1]
result+=len[0]*len[2]
print(result*n)