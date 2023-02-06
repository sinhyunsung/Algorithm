import sys


class q:
    def __init__(self):
        self.memory=[]
        self.popidx=0
    
    def push(self,x):
        self.memory.append(x)
    
    def front(self):
        if len(self.memory)==self.popidx:
            print(-1)
        else:
            print(self.memory[self.popidx])
    
    def back(self):
        if len(self.memory)==self.popidx:
            print(-1)
        else:
            print(self.memory[-1])
    
    def size(self):
        print(len(self.memory)-self.popidx)
    
    def empty(self):
        if len(self.memory)==self.popidx:
            print(1)
        else:
            print(0)
    
    def pop(self):
        if len(self.memory)==self.popidx:
            print(-1)
        else:
            print(self.memory[self.popidx])
            self.popidx+=1

a=int(input())
Q=q()
for i in range(a):
    b=sys.stdin.readline().rstrip()
    
    if b[0:4]=='push':
        Q.push(int(b.split()[1]))
    elif b=='front':
        Q.front()
    elif b=='back':
        Q.back()
    elif b=='size':
        Q.size()
    elif b=='empty':
        Q.empty()
    else:
        Q.pop()
    
