import sys
while True:
    a=sys.stdin.readline()
    if a=='':
        break
    else:
        a=a.split()
        print(int(a[0])+int(a[1]))