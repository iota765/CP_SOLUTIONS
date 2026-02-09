#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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
    vector<int>dp(n+1,1e9);
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            dp[j]=min(dp[j],dp[i]+dp[j/i]);
        }
    }
    for(int i=1;i<=n;i++){
        if(dp[i]==1e9) dp[i]=-1;
    }
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    } 
    cout<<endl;

}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}