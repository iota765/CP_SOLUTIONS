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
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    cin>>a;
    for(int i=0;i<n;i++){
        int r=a[i]%(k+1);
        a[i]+=r*k;
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