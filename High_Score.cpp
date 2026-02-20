#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>edges(m);
    vector<vector<int>>graph(n+1);
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges[i]={u,{v,wt}};
        graph[u].push_back(v);
    }

    vector<int>dist(n+1,LLONG_MIN);
    dist[1]=0;
    for(int i=0;i<n-1;i++){
      for(auto &[u,vw]:edges){
            int v=vw.first;
            int wt=vw.second;
            if(dist[u]!=LLONG_MIN and dist[u]+wt>dist[v]){
            dist[v]=dist[u]+wt;
        }
      }
  }  

    set<int>cycle_nodes;
    for(auto it:edges){
        int u=it.first;
        int v=it.second.first;
        int wt=it.second.second;
        if(dist[u]!=LLONG_MIN and dist[u]+wt>dist[v]){
                cycle_nodes.insert(v);
        }
    }
    vector<bool>visited(n+1,false);
    queue<int>cycle_queue;
    queue<int>q;
    q.push(1);
    queue<int>cycle_q;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(visited[u]) continue;
        visited[u]=true;
        if(cycle_nodes.count(u)){
            cycle_q.push(u);
        }
        for(int v:graph[u]){
            if(!visited[v]){
                q.push(v);
            }
        }
    }
    visited.assign(n+1,false);
    bool can_reach_n=false;
    while(!cycle_q.empty()){
        int u=cycle_q.front();
        cycle_q.pop();
        if(visited[u]) continue;
        visited[u]=true;
        if(u==n){
            can_reach_n=true;
            break;
        }
        for(int v:graph[u]){
            if(!visited[v]){
                cycle_q.push(v);
            }
        }
    }
    if(can_reach_n){
        cout<<-1;
    }
    else{
        cout<<dist[n];
    }


    
    
}

signed main() {
    fastio
    solve();
}