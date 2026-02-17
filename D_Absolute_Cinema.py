import sys
from bisect import bisect_left, bisect_right
from collections import deque, Counter
input = sys.stdin.readline

def solve():
    n=int(input())
    f=[0]+list(map(int,input().split()))
    ans=[0]*(n+1)
    sum1=0
    sum2=0
    for i in range(2,n):
        ans[i]=(f[i+1]+f[i-1]-2*f[i])//2
    x=0
    y=0
    for i in range(1,n):
        x+=ans[i]*(n-i)
    ans[1]=(f[n]-x)//(n-1)

    for i in range(2,n):
        y+=(i-1)*ans[i]
    ans[n]=(f[1]-y)//(n-1)

    print(*ans[1:])

if __name__ == "__main__":
    t_str = input().strip()
    if t_str:
        t = int(t_str)
        while t > 0:
            solve()
            t -= 1