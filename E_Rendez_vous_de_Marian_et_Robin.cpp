#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;

vector<vector<pair<int,int>>> graph;

vector<vector<int>> dijkstra(int start, vector<int>& horse, int n){

    vector<vector<int>> dist(n+1, vector<int>(2, INF));

    priority_queue<tuple<int,int,int>,
    vector<tuple<int,int,int>>, greater<>> pq;

    dist[start][0] = 0;
    pq.push({0,start,0});

    while(!pq.empty()){

        auto [d,u,state] = pq.top();
        pq.pop();

        if(d > dist[u][state]) continue;

        if(horse[u] && state == 0){
            if(dist[u][1] > d){
                dist[u][1] = d;
                pq.push({d,u,1});
            }
        }

        for(auto [v,w] : graph[u]){

            int cost = (state ? w/2 : w);

            if(dist[v][state] > d + cost){
                dist[v][state] = d + cost;
                pq.push({dist[v][state], v, state});
            }
        }
    }

    return dist;
}

void solve(){

    int n,m,h;
    cin >> n >> m >> h;

    vector<int> horse(n+1,0);

    for(int i=0;i<h;i++){
        int x;
        cin >> x;
        horse[x] = 1;
    }

    graph.assign(n+1,{});

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;

        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    auto distM = dijkstra(1,horse,n);
    auto distR = dijkstra(n,horse,n);

    int ans = INF;

    for(int i=1;i<=n;i++){

        int tM = min(distM[i][0], distM[i][1]);
        int tR = min(distR[i][0], distR[i][1]);

        if(tM == INF || tR == INF) continue;

        ans = min(ans, max(tM,tR));
    }

    if(ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
}

signed main(){
    fastio

    int t;
    cin >> t;

    while(t--) solve();
}