x,y=map(int,input().split())
num=int(input())

x_list=[x]
y_list=[y]

def div(list,v):
    sum=0
    for idx,n in enumerate(list):
        sum+=n
        if v<=sum:
            del list[idx]
            list.insert(idx,sum-v)
            list.insert(idx, n-(sum-v))
            break


for i in range(num):
    type, cm = map(int, input().split())
    if type==0:
        div(y_list,cm)
    else:
        div(x_list,cm)

print(max(x_list)*max(y_list))