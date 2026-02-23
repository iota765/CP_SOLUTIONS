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
void solve() {
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    vector<int>indegree(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    queue<int>q;
    vector<int>order;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        order.push_back(node);
        for(int neighbour:graph[node]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }

    }
    vector<int>dp(n+1,INT_MIN);
    vector<int>parent(n+1,-1);
    dp[1]=0;
    for(int u:order){
        if(dp[u]==INT_MIN) continue;
        for(int v:graph[u]){
            if(dp[v]<dp[u]+1){
                dp[v]=dp[u]+1;
                parent[v]=u;
            }
        }
    }
    if(dp[n]==INT_MIN){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vector<int>path;
    int curr=n;
    while(curr!=-1){
        path.push_back(curr);
        curr=parent[curr];
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(auto ele:path){
        cout<<ele<<" ";
    }
    cout<<endl;


}

signed main() {
    fastio
    solve();
}