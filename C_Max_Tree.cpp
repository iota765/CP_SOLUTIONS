#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    vector<int>indeg(n+1);
    queue<int>q;
    for(int i=0;i<n-1;i++){
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        if(x<=y){
        adj[u].push_back(v);
        indeg[v]++;
        }
        else{
        adj[v].push_back(u);
        indeg[u]++;
        }
    }
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
        q.push(i);
        ans.push_back(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
        indeg[it]--;
        if(indeg[it]==0){
            ans.push_back(it);
            q.push(it);
        }
        }
    
  }
  vector<int>p(n+1);
  for(int i=0;i<n;i++){
    p[ans[i]]=i+1;
  }
  for(int i=1;i<=n;i++){
    cout<<p[i]<<" ";
  }
  cout<<endl;
}

signed main() {
    fastio
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}