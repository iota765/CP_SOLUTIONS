#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
const int MOD=1e9+7;
const int INF=1e18;
template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
vector<vector<pair<int,int>>>graph;
void solve() {
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    vector<vector<int>>dp(n+1,vector<int>(4,INF));
    dp[1][0]=0;
    dp[1][1]=1;
    dp[1][2]=0;
    dp[1][3]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto[curdis,node]=pq.top();
        pq.pop();
        if(curdis>dp[node][0]) continue;
        for(auto[nbr,weight]:graph[node]){
            int new_dis=curdis+weight;
            if(new_dis<dp[nbr][0]){
                dp[nbr][0]=new_dis;
                dp[nbr][1]=dp[node][1];
                dp[nbr][2]=dp[node][2]+1;
                dp[nbr][3]=dp[node][3]+1;
                pq.push({new_dis,nbr});
            }
            else if(new_dis==dp[nbr][0]){
                dp[nbr][1]=(dp[node][1]+dp[nbr][1])%MOD;
                dp[nbr][2]=min(dp[nbr][2],dp[node][2]+1);
                dp[nbr][3]=max(dp[nbr][3],dp[node][3]+1);
            }
        }
    }
    for(auto ele:dp[n]){
        cout<<ele<<" ";
    }
}

signed main() {
    fastio
    solve();
}