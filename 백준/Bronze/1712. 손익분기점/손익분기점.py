

a=list(map(int,input().split()))

if a[1]<a[2]:
    print(int(a[0]/(a[2]-a[1]))+1)
else:
    print(-1)