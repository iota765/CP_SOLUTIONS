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
vector<int>indeg;
void solve() {
    int n,k;
    cin>>n>>k;
    graph.assign(n,vector<int>{});
    indeg.assign(n,0);
    for(int i=0;i<k;i++){
        vector<int>a(n);
        for(int j=0;j<n;j++){
            cin>>a[j];
            a[j]--;
        }
        for(int j=1;j<n-1;j++){
            int u=a[j];
            int v=a[j+1];
            graph[u].push_back(v);
            indeg[v]++;
        } 
    }

    queue<int>q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(auto neigh:graph[node]){
            indeg[neigh]--;
            if(indeg[neigh]==0){
                q.push(neigh);
            }
        }
    }
    if(ans.size()==n){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}