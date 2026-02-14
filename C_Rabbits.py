import sys
from bisect import bisect_left, bisect_right
from collections import deque, Counter
input = sys.stdin.readline
def solve():
    n=int(input())
    s=input().strip()
    ok=True
    curr=(s[0]=='1')
    cnt=0

    for i in range(n):
        if s[i]=='0':
            cnt+=1
        if i==0:
            continue
        if s[i]==s[i-1]=='0':
            curr=False
        if s[i]==s[i-1]=='1':
            if curr and cnt%2==1:
                ok=False
            curr=True
            cnt=0

    if curr and cnt%2==1 and s[-1]=='1':
        ok=False

    if ok:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    t_str = input().strip()
    if t_str:
        t = int(t_str)
        while t > 0:
            solve()
            t -= 1