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
    cin >> n;
    vector<int>p(n);
    vector<int>a(n);
    cin>>p;
    cin>>a;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[p[i]]=i;
    }
    for(int i=0;i<n-1;i++){
        if(mp[a[i]]>mp[a[i+1]]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;

}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}