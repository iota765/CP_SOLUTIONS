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
    vector<int>a(2*n+1);
    for(int i=1;i<=2*n;i++){
        cin>>a[i];
    }
    

}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}