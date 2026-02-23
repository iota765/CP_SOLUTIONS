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
    queue<int>q;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    stack<int>s;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        s.push(node);
        for(auto neighbour:graph[node]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    if(s.size()!=n){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vector<int>ans;
    while(!s.empty()){
        int a=s.top();
        s.pop();
        ans.push_back(a);
    }
    reverse(ans.begin(),ans.end());
    for(auto ele:ans){
        cout<<ele<<" ";
    }
    cout<<endl;
}

signed main() {
    fastio
    solve();
}