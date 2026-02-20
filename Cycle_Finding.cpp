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
    vector<tuple<int,int,int>>edges;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    vector<int>dis(n+1,0);
    vector<int>relaxant(n+1,-1);
    int x=-1;
    for(int i=0;i<n;i++){
        x=-1;
        for(auto it:edges){
            int u=get<0>(it);
            int v=get<1>(it);
            int w=get<2>(it);
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                relaxant[v]=u;
                x=v;
            }
        }
    }
        if(x==-1){
            cout<<"NO"<<endl;
            return;
        }

        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            x=relaxant[x];
        }

        vector<int>cycle;
        for(int curr=x;;curr=relaxant[curr]){
            cycle.push_back(curr);
            if(curr==x and cycle.size()>1){
                break;
            }
        }
        reverse(cycle.begin(),cycle.end());
        for(auto ele:cycle){
            cout<<ele<<" ";
        }

}

signed main() {
    fastio
    solve();
}