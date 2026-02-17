#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
vector<vector<int>>adj;
vector<int>dp;
const int mod=1e9+7;

int dfs1(int x,int parent){
    bool isLeaf=true;
    int sum=0;
    for(int child:adj[x]){
        if(child==parent) continue;
        isLeaf=false;
        sum=(sum+dfs1(child,x))%mod;

    }
    if (isLeaf){
        return dp[x]=1;
    }
    return dp[x]=(sum+3)%mod;
}

void dfs2(int x,int parent){
    for(int child:adj[x]){
        if(child==parent) continue;
        dp[child]=(dp[child]+dp[x])%mod;
        dfs2(child,x);
    }
}

void solve() {
    int n;
    cin>>n;
    adj.assign(n,{});
    dp.assign(n,0);

    for(int i=0;i<n;i++){
        int L,R;
        cin>>L>>R;
        L--,R--;
        if(L!=-1){
            adj[i].push_back(L);
            adj[L].push_back(i);
        }
        if(R!=-1){
            adj[i].push_back(R);
            adj[R].push_back(i);
        }
    }
    
    dfs1(0,-1);
    dfs2(0,-1);
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;   
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}