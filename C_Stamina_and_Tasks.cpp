#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

void solve() {

    int n;
    cin >> n;

    vector<pair<double,double>> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }

    vector<double> dp(n+1,0);

    for(int i=n-1;i>=0;i--){

        double c = v[i].first;
        double p = v[i].second / 100.0;

        dp[i] = max(dp[i+1], c + (1-p)*dp[i+1]);
    }

    cout << fixed << setprecision(10) << dp[0] << "\n";
}

signed main() {
    fastio
    int t; cin >> t;
    while(t--) solve();
}
