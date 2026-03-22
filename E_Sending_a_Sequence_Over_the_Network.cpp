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
    vector<bool>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(dp[i-1] and i+x<=n){
            dp[i+x]=1;
        }
        if(i-x-1>=0){
            dp[i]=dp[i] || dp[i-x-1];
        }
    }
    if(dp[n]==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}