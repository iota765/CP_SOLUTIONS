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
    int n,m,h;
    cin>>n>>m>>h;
    vector<pair<int,int>>ops;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        int b,c;
        cin>>b>>c;
        b--;
        ops.push_back({b,c});
    }
    int last=0;
    for(int i=0;i<m;i++){
        int idx=ops[i].first;
        int x=ops[i].second;
        a[idx]+=x;
        if(a[idx]>h){
        for(int j=i;j>=last;j--){
            auto ele =ops[j];
            int i2=ele.first;
            int x2=ele.second;
            a[i2]-=x2;
        }
        last=i+1;
    }   
    }
    
    for(auto ele:a){
        cout<<ele<<" ";
    }
    cout<<endl;
    
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}