#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
vector<int>depth;
vector<int>visited;
vector<int>v;
vector<vector<int>>graph;
vector<int>sub;

void dfs(int node,int parent){
    for(int child:graph[node]){
        if(child==parent) continue;
        depth[child]=depth[node]+1;
        dfs(child,node);
        sub[node]+=sub[child]+1;
    }
    v[node]=depth[node]-sub[node];
}

void solve() {
    int n,k;
    cin>>n>>k;
    graph.resize(n);
    depth.assign(n,0);
    sub.assign(n,0);
    v.assign(n,0);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans=0;
    dfs(0,-1);
    sort(v.rbegin(),v.rend());
    for(int i=0;i<k;i++){
        ans+=v[i];
    }
    cout<<ans<<endl;
}

signed main() {
    fastio
    solve();
}