import sys
from bisect import bisect_left, bisect_right
from collections import deque, Counter
input = sys.stdin.readline

def solve():
    n,m,l=map(int,input().split())
    a=[0]+list(map(int,input().split()))+[0]
    ans=0
    for i in range(1,n+1):
        if(a[i]>l):
            ans+=a[i-1]<=l
    for _ in range(m):
        s=list(map(int,input().split()))
        if(s[0]==0):
            print(ans)
        else:
            p=s[1]
            d=s[2]
            if(a[p]<=l and a[p]+d>l):
                ans+=1-(a[p-1]>l)-(a[p+1]>l)
            a[p]+=d
              
if __name__ == "__main__":
    solve()