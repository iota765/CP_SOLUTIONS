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
    int n,l,k;
    cin>>n>>l>>k;
    vector<int>d(n);
    cin>>d;
    vector<int>a(n);
    cin>>a;
    d.push_back(l);
    vector<vector<int>>dp(n+1,vector<int>(k+1,LLONG_MAX/10));

    for(int j=0;j<=k;j++) dp[n][j]=0;

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=k;j++){
            for(int nxt=i+1;nxt<=min(n,i+j+1);nxt++){
                int removed=nxt-i-1;
                int cost=a[i]*(d[nxt]-d[i])+dp[nxt][j-removed];
                dp[i][j]=min(dp[i][j],cost);
            }
        }
    }
    cout<<dp[0][k]<<endl;
}

signed main() {
    fastio
    solve();
}