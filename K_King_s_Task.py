import sys
from bisect import bisect_left, bisect_right
from collections import deque, Counter

input = sys.stdin.readline

def is_sorted(p):
    return all(p[i]==i+1 for i in range(len(p)))
    
def op1(p):
    for i in range(0,len(p),2):
        p[i],p[i+1]=p[i+1],p[i]

def op2(p,n):
    for i in range(n):
        p[i],p[i+n]=p[i+n],p[i]

def simulate(p,n,start_type):
    original=p[:]
    max_steps=max(2*n,4)
    t=start_type
    for step in range(1,max_steps+1):
        if t==1:
            op1(p)
        else:
            op2(p,n)
        if is_sorted(p):
            return step
        if p==original:
            break
        t=3-t
    return float('inf')

def solve():
    n=int(input().strip())
    p=list(map(int,input().split()))
    if is_sorted(p):
        print(0)
        return
    ans=min(simulate(p[:],n,1),
            simulate(p[:],n,2))
    
    if ans==float('inf'):
        print(-1)
    else:
        print(ans)

if __name__ == "__main__":
    solve()