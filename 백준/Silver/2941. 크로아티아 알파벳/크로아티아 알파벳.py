sumV=0

a=input()
sumV+=a.count('c=')
a=a.replace('c=','*')
sumV+=a.count('c-')
a=a.replace('c-','*')
sumV+=a.count('dz=')
a=a.replace('dz=','*')
sumV+=a.count('d-')
a=a.replace('d-','*')
sumV+=a.count('lj')
a=a.replace('lj','*')
sumV+=a.count('nj')
a=a.replace('nj','*')
sumV+=a.count('s=')
a=a.replace('s=','*')
sumV+=a.count('z=')
a=a.replace('z=','*')
a=a.replace('*','')


sumV+=len(a)

print(sumV)