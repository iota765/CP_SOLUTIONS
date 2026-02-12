import sys
from collections import Counter
input = sys.stdin.readline

def solve():
    n = int(input())
    s = input().strip()
    freq=[[0,chr(ord('a')+i)] for i in range(26)]
    for ch in s:
        freq[ord(ch)-ord('a')][0]+=1
    freq.sort(reverse=True)
    best_k=1
    changes=n

    for k in range(1,27):
        if n%k!=0:
            continue
        limit=n//k
        unchanged=0
        for i in range(k):
            unchanged+=min(freq[i][0],limit)

        if n-unchanged<changes:
            changes=n-unchanged
            best_k=k
    mp={}
    for i in range(best_k):
        mp[freq[i][1]]=n//best_k
    
    ans=[' ']*n
    for i in range(n):
        if s[i] in mp and mp[s[i]]>0:
            ans[i]=s[i]
            mp[s[i]]-=1

    for i in range(n):
        if(ans[i]!=' '):
            continue
        for ch in mp.keys():
            if mp[ch]>0:
                ans[i]=ch
                mp[ch]-=1
                break
    print(changes)
    print("".join(ans))

if __name__ == "__main__":
    t = int(input())
    while t:
        solve()
        t -= 1
