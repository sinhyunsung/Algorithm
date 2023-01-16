import sys
 
number = int(sys.stdin.readline())

 
for i in range(number):
    a =sys.stdin.readline().split()
    print(int(a[0]) + int(a[1]))
