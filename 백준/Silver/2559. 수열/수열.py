total_num,sum_num=map(int,input().split())

li=list(map(int,input().split()))

result=sum(li[0:sum_num])

sum=sum(li[0:sum_num])

for i in range(sum_num,total_num):
    sum=sum-li[i-sum_num]+li[i]
    if result<sum:
        result=sum

print(result)
