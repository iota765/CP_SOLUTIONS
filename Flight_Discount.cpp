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
    vector<vector<pair<int,int>>>graph(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
    // distance,node,state
    // 0-1/0 , 
    q.push({0,1,0});
    vector<vector<int>>dist(n+1, vector<int>(2, 1e18));
    dist[1][0] = 0;
    while(!q.empty()){
        auto [curdis, node, used] = q.top();
        q.pop();
        if(curdis>dist[node][used]) continue;
        for(auto[nbr,w]:graph[node]){
            if(used==0){
            if(curdis+w<dist[nbr][0]){
                dist[nbr][0]=curdis+w;
                q.push({dist[nbr][0],nbr,0});
            }

            if(curdis+w/2<dist[nbr][1]){
                dist[nbr][1]=curdis+w/2;
                q.push({dist[nbr][1],nbr,1});
            }
         }
         else{
            if(curdis+w<dist[nbr][1]){
                dist[nbr][1]=curdis+w;
                q.push({dist[nbr][1],nbr,1});
            }
         }

        }
    }
    cout<<dist[n][1];
}

signed main() {
    fastio
    solve();
}