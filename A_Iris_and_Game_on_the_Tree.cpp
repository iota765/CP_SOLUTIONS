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
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    vector<int>indeg(n,0);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        indeg[u]++;
        indeg[v]++;
    }
    string s;
    cin>>s;
    int u=0,o=0,z=0,q=0;
    int ans=0;
    for(int i=1;i<n;i++){
        if(indeg[i]==1){
            if(s[i]=='1') o++;
            else if(s[i]=='0') z++;
            else q++;
        }
        else{
            if(s[i]=='?') u++;
        }
    }

    if(s[0]!='?'){
        ans+=(s[0]=='1'?z:o);
        ans+=(q+1)/2;
    }

    else{
        if(o==z and u%2){
            ans=o+(q+1)/2;
        }
        else{
            ans=max(o,z)+q/2;
        }
    }
    cout<<ans<<endl;

}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}