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
    int n,k,z;
    cin>>n>>k>>z;
    vector<int>a(n);
    cin>>a;
    int ans=0;
    for(int i=0;i<=min(z,k/2);i++){
        int r=min(n-1,k-2*i);
        if(r<0) continue;
        int base=accumulate(a.begin(),a.begin()+r+1,0LL);
        int best=0;
        for(int j=1;j<=min(r+1,n-1);j++){
            int sum=a[j-1]+a[j];
            best=max(sum,best);
        }
        ans=max(ans,best*i+base);
    }
    cout<<ans<<endl;
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}