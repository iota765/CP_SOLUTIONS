import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    
    l = [0]*(n+1)
    r = [0]*(n+1)
    
    for i in range(1, n+1):
        l[i], r[i] = map(int, input().split())
    
    adj = [[] for _ in range(n+1)]
    
    for _ in range(n-1):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
    
    dp = [[0, 0] for _ in range(n+1)]
    
    parent = [-1]*(n+1)
    order = []
    stack = [1]
    parent[1] = 0
    
    while stack:
        node = stack.pop()
        order.append(node)
        for nei in adj[node]:
            if nei != parent[node]:
                parent[nei] = node
                stack.append(nei)
    
    for v in reversed(order):
        for u in adj[v]:
            if u == parent[v]:
                continue
            
            dp[v][0] += max(
                dp[u][0] + abs(l[v] - l[u]),
                dp[u][1] + abs(l[v] - r[u])
            )
            
            dp[v][1] += max(
                dp[u][0] + abs(r[v] - l[u]),
                dp[u][1] + abs(r[v] - r[u])
            )
    
    print(max(dp[1][0], dp[1][1]))


t = int(input())
for _ in range(t):
    solve()
