#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
vector<vector<int>>graph;
vector<int>visited;
vector<int>parent;
int cycle_start=-1;
int cycle_end=-1;
vector<int>path_visited;

bool dfs(int node){
    visited[node]=true;
    path_visited[node]=true;
    for(int neighbour:graph[node]){
        if(!visited[neighbour]){
            parent[neighbour]=node;
            if(dfs(neighbour)){
                return true;
            }
        }
        else if(path_visited[neighbour]){
            cycle_end=neighbour;
            cycle_start=node;
            return true;
        }
    }
    path_visited[node]=false;
    return false;

}
void solve() {
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    visited.assign(n+1,false);
    path_visited.assign(n+1,false);
    parent.assign(n+1,-1);

    for(int i=1;i<=n;i++){
        if(!visited[i] and dfs(i)){
            break;
        }
    }
    if(cycle_start==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int>cycle;
        cycle.push_back(cycle_start);
        int curr=cycle_end;
        while(curr!=cycle_start){
            cycle.push_back(curr);
            curr=parent[curr];
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(),cycle.end());
        cout<<cycle.size()<<endl;
        for(int node:cycle){
            cout<<node<<" ";
        }
        cout<<endl;
    }

}

signed main() {
    fastio
    solve();
}