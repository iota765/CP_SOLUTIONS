import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    a = [0] + list(map(int, input().split()))
    
    for i in range(n//2 - 1, 0, -1):
        if a[i] == a[i+1] or a[n-i+1] == a[n-i]:
            a[i], a[n-i+1] = a[n-i+1], a[i]

    cnt = 0
    for i in range(1, n):
        if a[i] == a[i+1]:
            cnt += 1
    
    print(cnt)

t = int(input())
for _ in range(t):
    solve()
