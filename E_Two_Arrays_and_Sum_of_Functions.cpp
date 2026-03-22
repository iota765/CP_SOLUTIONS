#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
const int mod=998244353;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int ans=0;
    vector<int>temp;
    for(int i=0;i<n;i++){
        int c=(i+1)*(n-i)*a[i];
        temp.push_back(c);
    }
    sort(temp.rbegin(),temp.rend());
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        ans=(ans+(temp[i]%mod)*b[i])%mod;
    }
    cout<<ans<<endl;

}

signed main() {
    fastio
    // int t; cin >> t;
    // while (t--) solve();
    // return 0;
    solve();
}