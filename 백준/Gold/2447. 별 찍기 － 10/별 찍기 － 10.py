a=int(input())
area=[[' ']*a for i in range(a)]

def star(x,y,num):
    global area
    if num==3:
        area[y][x]='*'
        area[y][x+1]='*'
        area[y][x+2]='*'
        area[y+1][x]='*'
        area[y+1][x+2]='*'
        area[y+2][x]='*'
        area[y+2][x+1]='*'
        area[y+2][x+2]='*'
    else:
        
        num_3=int(num/3)
        
        star(x,y,num_3)
        star(x+num_3,y,num_3)
        star(x+num_3*2,y,num_3)
        star(x,y+num_3,num_3)
        star(x+num_3*2,y+num_3,num_3)
        star(x,y+num_3*2,num_3)
        star(x+num_3,y+num_3*2,num_3)
        star(x+num_3*2,y+num_3*2,num_3)
        
star(0,0,a)

for i in range(a):
    for j in range(a):
        print(area[i][j],end='')
    print('')