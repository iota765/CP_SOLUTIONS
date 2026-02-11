import sys
from collections import defaultdict

input = sys.stdin.readline

def solve():
    n = int(input())
    s = input().strip()

    a = s.count('a')
    b = s.count('b')

    if a == b:
        print(0)
        return

    d = a-b

    freq = dict()
    freq[0] = -1   

    cnt = 0
    ans = float('inf')

    for i, c in enumerate(s,1):

        if c == 'a':
            cnt += 1
        else:
            cnt -= 1

        if cnt == d:
            ans = min(ans, i)

        if (cnt - d) in freq:
            ans = min(ans, i - freq[cnt - d])


        freq[cnt] = i

    if ans == float('inf') or ans==n:
        print(-1)
    else:
        print(ans)

if __name__ == "__main__":
    t = int(input())
    while t:
        solve()
        t -= 1
