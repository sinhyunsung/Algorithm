a=int(input())
for i in range(a):
    b=input().split()
    print("Case #%d:" % (i+1),b[0],'+',b[1],'=',int(b[0])+int(b[1]))