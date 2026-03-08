#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
vector<vector<pair<int,int>>>graph;

void solve() {
    int n,m;
    cin>>n>>m;
     graph.assign(n, vector<pair<int,int>>());
     vector<bool>visited(n,false);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    /// {cost,node}
    pq.push({0,0});
    int ans=0;
    while(!pq.empty()){
        auto ele=pq.top();
        pq.pop();
        int node=ele.second;
        if(visited[node]) continue;
        int cost=ele.first;
        visited[node]=true;
        ans+=cost;
        for(auto ele:graph[node]){
            int node=ele.first;
            int cost=ele.second;
            if(visited[node]) continue;
            pq.push({cost,node});

        }
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            cout<<"IMPOSSIBLE";
            return;
        }
    }
    cout<<ans; 
}

signed main() {
    fastio
    solve();
}