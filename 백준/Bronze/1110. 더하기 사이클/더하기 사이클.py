num=int(input())
num2=100
i=0
while num!=num2:
    if i==0:
        num2=num
    a=num2%10
   
    b=int(num2/10) 
   
    num2=int(a*10+int((a+b)%10))
        
    i+=1
        
print(i)