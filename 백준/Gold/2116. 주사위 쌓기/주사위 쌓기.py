n=int(input())

dice=[]

for i in range(n):
    dice.append(list(map(int,input().split())))

result=[]

def cal(li,under_num):
    idx=li.index(under_num)
    if idx==0:
        return max(li[1:5]),li[5]
    elif idx==1:
        return max(li[0],li[2],li[4],li[5]),li[3]
    elif idx==2:
        return max(li[0],li[1],li[3],li[5]),li[4]
    elif idx==3:
        return max(li[0],li[2],li[4],li[5]),li[1]
    elif idx==4:
        return max(li[0],li[1],li[3],li[5]),li[2]
    elif idx==5:
        return max(li[1],li[2],li[3],li[4]),li[0]

for k in range(1,7):
    sum=0
    b=k
    for i in dice:
        l=i
        a, b = cal(l, b)
        sum += a
    result.append(sum)

print(max(result))