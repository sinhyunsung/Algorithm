def self_number(num):
    sum=num
    while num!=0:
        sum+=num%10
        num=int(num/10)
    return sum

l=[i for i in range(10000)]

for i in range(10000):
    try:
        l.remove(self_number(i))
    except:
        continue

for i in l:
    print(i)