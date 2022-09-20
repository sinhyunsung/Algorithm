
import queue

n=int(input())
b=[]
for i in range(n):
    b.append(list(map(int,list(input()))))

c=[]
result=[]
bfs = queue.Queue()

for i in range(n):
    for j in range(n):
        if b[i][j]==1:
            bfs.put([i,j])
            b[i][j]=0
            while bfs.qsize()!=0:
                tmp=bfs.get()
                if tmp[0]>0 and b[tmp[0]-1][tmp[1]]==1:
                    bfs.put([tmp[0]-1,tmp[1]])
                    b[tmp[0]-1][tmp[1]]=0
                if tmp[1]>0 and b[tmp[0]][tmp[1]-1]==1:
                    bfs.put([tmp[0],tmp[1]-1])
                    b[tmp[0]][tmp[1]-1]=0
                if tmp[0]<n-1 and b[tmp[0]+1][tmp[1]]==1:
                    bfs.put([tmp[0]+1,tmp[1]])
                    b[tmp[0]+1][tmp[1]]=0
                if tmp[1]<n-1 and b[tmp[0]][tmp[1]+1]==1:
                    bfs.put([tmp[0],tmp[1]+1])
                    b[tmp[0]][tmp[1]+1]=0
                c.append(tmp)
            else:
                result.append(len(c))
                c=[]
result.sort()
print(len(result))
for i in range(len(result)):
    print(result[i])
