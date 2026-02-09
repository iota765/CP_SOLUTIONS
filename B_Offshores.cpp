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
    int n,x,y;
    cin>>n>>x>>y;
    vector<int>a(n);
    cin>>a;
    int sum=0;
    int ans=LLONG_MIN;
    for(int i=0;i<n;i++){
      sum+=a[i]/x*y;
    }
    for(int i=0;i<n;i++){
      int curr=sum+a[i]-(a[i]/x)*y;
      ans=max(curr,ans);
    }
    cout<<ans<<endl;

}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}