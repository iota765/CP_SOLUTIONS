#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
int n;
vector<int>vis;
vector<vector<int>>adj;

void dfs(int i, int &cycle ,int &len){
    vis[i]=true;
    len++;
    if(adj[i].size()<2) cycle=false;

    for(auto j:adj[i]){
        if(vis[j]) continue;
        dfs(j,cycle,len);
    }
}
void solve() {
    cin>>n;
    adj.assign(n,{});
    vis.assign(n,false);

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        x--;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    int b=0,c=0;
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        int cycle=1,len=0;
        dfs(i,cycle,len);
        if(cycle && len>2){
            c++;
        }
        else b++;
    }
    
    if(b){
        cout<<c+1<<" "<<c+b<<endl;
    }
    else cout<<c<<" "<<c<<endl;


}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}