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
const int MOD=1e9+7;
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int>order;
    vector<int>indegree(n+1,0);
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    queue<int>q;
    for(int i=1;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }
    while(!q.empty()){
        int node=q.front();
        order.push_back(node);
        q.pop();
        for(int neighbour:graph[node]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0) q.push(neighbour);
        }
    }
    vector<int>dp(n+1,0);
    dp[1]=1;
    for(int node:order){
        for(int neighbour:graph[node]){
            dp[neighbour]=(dp[node]+dp[neighbour])%MOD;
        }
    }
    cout<<dp[n]<<endl;
}

signed main() {
    fastio
    solve();
}