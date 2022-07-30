m=int(input())
a=list(map(int,input().split()))

n=int(input())
b=list(map(int,input().split()))
def quick_sort(l,start,last):
    if start>=last:
        return
    p=start
    i=start+1
    j=last
    while(i<=j):
        if l[j]<l[p] and l[i]>l[p]:
            temp=l[i]
            l[i]=l[j]
            l[j]=temp
        if j>0 and l[j]>=l[p]:
            j-=1
        elif i < len(l) - 1 and l[i] <= l[p]:
            i+=1
    temp = l[j]
    l[j] = l[p]
    l[p] = temp

    quick_sort(l,start,j-1)
    quick_sort(l, j+1, last)

def binary_search(l,target):
    start=0
    last=len(l)-1
    search=0
    while(start<=last):
        mid=start+(last-start)//2
        if l[mid]==target:
            search=1
            break
        elif l[mid]<target:
            start=mid+1
        else:
            last=mid-1
    return search



#quick_sort(a,0,m-1)
a.sort()
for i in b:
    print(binary_search(a,i))