import sys
from bisect import bisect_left, bisect_right
from collections import deque, Counter  
input = sys.stdin.readline

def solve():
    pass


if __name__ == "__main__":
    t_str = input().strip()
    if t_str:
        t = int(t_str)
        while t > 0:
            solve()
            t -= 1