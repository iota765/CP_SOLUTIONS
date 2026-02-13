import sys
from bisect import bisect_left, bisect_right
from collections import deque, Counter
input = sys.stdin.readline

def check(T,x,t,n):
    l=0.0
    r=1e8
    for i in range (n):
        reach=T-t[i]
        if(reach<0):
            reach=0.0
        left=(x[i]-reach)
        right=(x[i]+reach)
        l=max(l,left)
        r=min(r,right)
        if(l>r):
            return False,0.0
    return True,(l+r)/2



def solve():
    n=int(input())
    x=list(map(int,input().split()))
    t=list(map(int,input().split()))
    l=0.0
    r=1e9
    best=0.0
    for i in range(60):
        mid=(l+r)/2.0
        ok,point=check(mid,x,t,n)
        if ok:
            r=mid
            best=point
        else:
            l=mid
    print(best)


if __name__ == "__main__":
    t_str = input().strip()
    if t_str:
        t = int(t_str)
        while t > 0:
            solve()
            t -= 1