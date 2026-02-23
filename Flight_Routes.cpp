#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
/// *** k shortest paths ***
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>>graph(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<vector<int>>dis(n+1);
    pq.push({0,1});
    while(!pq.empty()){
        auto ele=pq.top();
        int d=ele.first;
        int u=ele.second;
        pq.pop();
        if(dis[u].size()>=k) continue;
        dis[u].push_back(d);
        for(auto it:graph[u]){
            int v=it.first;
            int weight=it.second;
            int new_dis=d+weight;
            pq.push({new_dis,v});
        }
    }

    for(int i=0;i<dis[n].size();i++){
        cout<<dis[n][i]<<" ";
    }
    cout<<endl;

}

signed main() {
    fastio
    solve();
}