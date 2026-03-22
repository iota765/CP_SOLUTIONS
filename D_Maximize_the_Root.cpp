#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
const int INF=1e9;

vector<vector<int>>g;
vector<int>a;

bool check(int v,int x){
    if(x>INF) return false;
    if(v!=0){
        if(x>a[v]){
            x=x+(x-a[v]);
        }
    }
    if(g[v].size()==0) return x<=a[v];

    for(auto c:g[v]){
        if(!check(c,x)) return false;
    }
    return true;
}
void solve() {
    int n;
    cin>>n;
    g.clear();
    g.resize(n);
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    for(int i=1;i<n;i++){
        int p;
        cin>>p;
        p--;
        g[p].push_back(i);
    }
    int l=1;
    int r=INF;
    while(l<=r){
        int mid=l+(r-l)/2;
        if (check(0,mid)){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<a[0]+l-1<<endl;
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}