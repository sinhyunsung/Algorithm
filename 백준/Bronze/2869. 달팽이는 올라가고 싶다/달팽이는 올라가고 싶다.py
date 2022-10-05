a=list(map(int,input().split()))

day=(a[2]-a[0])//(a[0]-a[1]) +1
if (a[2]-a[0])%(a[0]-a[1])>0:
    day+=1
print(day)