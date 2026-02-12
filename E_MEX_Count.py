import sys
from bisect import bisect_left, bisect_right
from collections import deque, Counter

# Fast I/O
input = sys.stdin.readline

def solve():
    n = map(int, input().split())
    a = list(map(int, input().split()))
    freq=Counter(a)
    ans=[1]*(n+1)
    ans[0]=1

    for i in range(1,n):
        x=sum(1 for freq in freq.values()if freq==i)
        ans.append(x)
    
    print(*ans)




if __name__ == "__main__":
    t_str = input().strip()
    if t_str:
        t = int(t_str)
        while t > 0:
            solve()
            t -= 1