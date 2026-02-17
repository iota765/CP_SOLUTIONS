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
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    adj.assign(n+1,{});
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>visited(n+1,false);
    vector<int>dis(n+1,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // dis,node
    pq.push({0,1});
    dis[1]=0;
    while(!pq.empty()){
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if (d>dis[node]) continue;
        for(auto child:adj[node]){
            if(d+1<dis[child]){
                dis[child]=d+1;
                pq.push({dis[child],child});
            }
        }
    }
    vector<int>temp(k+1,0);
    for(int i=1;i<=n;i++){
        int p=a[i];
        int d=dis[i];
        temp[p]=max(temp[p],d);
    }
    for(int i=1;i<=k;i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;



    
}

signed main() {
    fastio
    solve();
}