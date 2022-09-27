import sys
ipt = sys.stdin.readline
S = set()
 
for i in range(0,int(ipt())):
    S.add(int(ipt()))
for i in sorted(S):
    print(i)
