def pi(num):
    
    if num==0:
        return 0
    if num==1:
        return 1
    else:
        return pi(num-1)+pi(num-2)

print(pi(int(input())))
    