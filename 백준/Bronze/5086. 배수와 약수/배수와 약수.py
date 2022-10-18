a,b=map(int,input().split())

while a!=0 or b!=0:
    if a%b==0:
        print('multiple')
    elif b%a==0:
        print('factor')
    else:
        print('neither')
    a,b=map(int,input().split())
