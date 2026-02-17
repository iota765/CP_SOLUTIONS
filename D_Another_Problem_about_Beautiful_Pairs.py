import sys
input = sys.stdin.readline

def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = [0] + list(map(int, input().split())) 
        
        rn = int(n ** 0.5)
        ans = 0

        for k in range(1, rn + 1):
            for j in range(1, n + 1):
                i = j - a[j] * k
                if 1 <= i <= n and a[i] == k:
                    ans += 1

        for k in range(1, rn + 1):
            for i in range(1, n + 1):
                if a[i] <= rn: 
                    continue
                j = i + k * a[i]
                if 1 <= j <= n and a[j] == k:
                    ans += 1
        
        print(ans)

solve()
