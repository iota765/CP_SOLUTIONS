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
    int p,q;
    cin>>p>>q;
    if(p>=q){
        cout<<"Alice"<<endl;
        return;
    }
    int d=q-p;
    if(p>=2*d and q>=3*d){
        cout<<"Bob"<<endl;
    }
    else{
        cout<<"Alice"<<endl;
    }

    // bob can make this difference constant


}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}