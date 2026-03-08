#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
vector<int>parent;
vector<int>size;
int comp_count,max_size;
int find_parent(int x){
    if(parent[x]==x) return x;
    return parent[x]=find_parent(parent[x]);
}

void union_by_size(int u,int v){
    int pu=find_parent(u);
    int pv=find_parent(v);
    if(pu==pv) return;
    if(size[pu]<size[pv]){
        parent[pu]=pv;
        size[pv]+=size[pu];
    }
    else{
        parent[pv]=pu;
        size[pu]+=size[pv];
    }
    comp_count--;
    max_size=max(max_size,max(size[pu],size[pv]));

}

void solve() {
    int n,m;
    cin>>n>>m;
    comp_count=n;
    max_size=LLONG_MIN;
    size.assign(n,1);
    parent.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    while(m--){
        int u,v;
        cin>>u>>v;
        u--,v--;
        union_by_size(u,v);
        cout<<comp_count<<" "<<max_size<<endl; 
    }
}

signed main() {
    fastio
    solve();
}