n = int(input())
for i in range(0,n):
    r,p=input().split(" ")
    r=int(r)
    p=int(p)
    cr=-1
    flag=True
    while (flag):
        cr=cr+1
        r=r-3
        p=p-2
        if(r<0 or p<0):
            flag=False
    s=(r+3)+(p+2)
    print(cr,s)
