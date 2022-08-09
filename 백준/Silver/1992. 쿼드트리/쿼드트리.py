
def sum_list(lst, res = 0):    
    for i in lst:
              if type(i) == list:
                    res += sum_list(i)
              else:
                    res += i
    return res


def dv(li,num):
    li1,li2,li3,li4=[],[],[],[]
    
    for i in range(num//2):
        li1.append(li[0:num//2][i][0:num//2])
        li2.append(li[num//2:num][i][0:num//2])
        li3.append(li[0:num//2][i][num//2:num])
        li4.append(li[num//2:num][i][num//2:num])
    return li1,li2,li3,li4

def fun(li,num):
    if sum_list(li)==num**2:
        print(1,end='')
    elif sum_list(li)==0:
        print(0,end='')
    else:
        a1,a2,a3,a4=dv(li,num)
        print('(',end='')
        fun(a1,num//2)
        fun(a3,num//2)
        fun(a2,num//2)
        fun(a4,num//2)
        print(')',end='')
        
a=int(input())
li=[]
for i in range(a):
    li.append(list(map(int,list(input()))))


fun(li,a)
