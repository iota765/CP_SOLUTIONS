import sys
import math
from bisect import bisect_left, bisect_right
from collections import deque, Counter
input = sys.stdin.readline

# def is_prime(x):
#     i=2
#     while(i*i<=x):
#         if(x%i==0):
#             return False
#         i+=1
#     return True


# def is_sc(x):
#     m=[]
#     i=2
#     while(i*i<=x):
#         while x%i==0:
#             x=x//i
#             m.append(i)
#         i+=1
#     if not x==1:
#         m.append(x)
#     return (len(m)>=3 or (len(m)==2 and m[0]==m[1]))


def solve():
    n=int(input())
    lst=list(map(int,input().split()))
    a={}

    for x in lst:
        i=2
        while i*i<=x:
            while x%i==0:
                x=x//i
                if i in a:
                    a[i]+=1
                else:
                    a[i]=1
            i+=1
        if x!=1:
            if x in a:
                a[x]+=1
            else:
                a[x]=1

    res,rem=0,0
    for num in a:
        cnt=a[num]
        res+=cnt//2
        rem+=cnt%2

    res+=rem//3
    print(res)


if __name__ == "__main__":
    t_str = input().strip()
    if t_str:
        t = int(t_str)
        while t > 0:
            solve()
            t -= 1