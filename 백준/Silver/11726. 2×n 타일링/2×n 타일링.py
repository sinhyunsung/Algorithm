n=int(input())
num=[1,1,1]

for i in range(n-1):
    num[2]=num[0]%10007+num[1]%10007
    num[0]=num[1]
    num[1]=num[2]

print(num[2]%10007)
        