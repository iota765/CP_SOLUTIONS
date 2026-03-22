#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
vector<vector<int>>graph,r_graph;
vector<bool>visited;
void dfs(int node,vector<vector<int>>&graph,vector<bool>&visited){
    if(visited[node])return;
    visited[node]=true;
    for(int x:graph[node]){
        dfs(x,graph,visited);
    }
}    
void solve() {
    int n,m;
    cin>>n>>m;
    visited.assign(n+1,false);
    graph.assign(n+1,vector<int>{});
    r_graph.assign(n+1,vector<int>{});
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        r_graph[v].push_back(u);
    }
    dfs(1,graph,visited);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            cout<<1<<" "<<i<<endl;
            return;
        }
    }
    visited.assign(n+1,false);
    dfs(1,r_graph,visited);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            cout<<i<<" "<<1<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
 
}

signed main() {
    fastio
    solve();
}