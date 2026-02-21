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
    vector<int>a(n);
    cin>>a;
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=max(a[i],a[(i+1)%n]);
    }
    ans-=*max_element(a.begin(),a.end());
    cout<<ans<<endl;

    
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
