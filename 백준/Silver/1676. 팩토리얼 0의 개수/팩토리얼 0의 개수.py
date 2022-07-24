a=int(input())
def num(x):
    o=0
    for i in range(1,x+1):
        while True:
            if i%5==0:
                o+=1
                i=i//5
            else:
                break
    return o


print(num(a))