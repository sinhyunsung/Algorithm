a=list(map(int,input().split()))

while a[0]!=0:
    a.sort()
    if pow(a[0],2)+pow(a[1],2)==pow(a[2],2):
        print('right')
    else:
        print('wrong')
    a=list(map(int,input().split()))