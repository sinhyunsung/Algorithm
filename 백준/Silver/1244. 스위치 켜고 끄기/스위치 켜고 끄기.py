import itertools

switch_num=int(input())

switch=list(map(int,input().split()))

human=int(input())

for i in range(human):
    sex,num=map(int,input().split())
    if sex==1:
        for j in range(num-1,switch_num,num):
            switch[j]=0 if switch[j] else 1

    else:
        mirror_num=0
        while(1):
            try:
                if switch[num-1+(mirror_num+1)]==switch[num-1-(mirror_num+1)] and num-1-(mirror_num+1)>=0:
                    mirror_num+=1
                else:
                    break
            except:
                break
        switch[num-1]=0 if switch[num-1] else 1
        for j in range(1,mirror_num+1):
            switch[num - 1+j] = 0 if switch[num - 1+j] else 1
            switch[num - 1-j] = 0 if switch[num - 1-j] else 1



for j,i in enumerate(switch,start=1):
    print(i,end=" ")
    if j%20==0:
        print()

