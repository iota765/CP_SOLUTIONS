#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}

int dfs(int node,int p,int depth,vector<vector<int>>&adj,vector<vector<int>>&d){
    int mx_dep=depth;
    for(auto x:adj[node]){
        if(x==p) continue;
        mx_dep=max(mx_dep,dfs(x,node,depth+1,adj,d));
    }
    d[depth].push_back(mx_dep);
    return mx_dep;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    vector<vector<int>>d(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }
    dfs(0,-1,0,adj,d);
    int ans=n;
    multiset<int>s;
    for(int i=0;i<n;i++){
        for(auto x:d[i]) s.insert(x);
        while(!s.empty() and (*s.begin())<i) s.erase(s.begin());
        ans=min(ans,n-s.size());
    }
    cout<<ans<<endl; 
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}