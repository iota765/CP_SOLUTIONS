#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
string a,b,c;
// int dfs(int i,int j,vector<vector<int>>&dp){
//     if(i==a.size() and j==b.size()){
//         return 0;
//     }
//     int k=i+j;
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     int ans=INT_MAX;
//     if(i<a.size()){
//         ans=min(ans,(a[i]!=c[k])+dfs(i+1,j,dp));
//     }
//     if(j<b.size()){
//         ans=min(ans,(b[j]!=c[k])+dfs(i,j+1,dp));
//     }
//     return dp[i][j]=ans;
// }

void solve() {
    cin>>a>>b>>c;
    int n=a.size();
    int m=b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int j=m-1;j>=0;j--){
        int k=n+j;
        dp[n][j]=(b[j]!=c[k])+dp[n][j+1];
    }

    for(int i=n-1;i>=0;i--){
        int k=i+m;
        dp[i][m]=(a[i]!=c[k])+dp[i+1][m];
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int k=i+j;
            dp[i][j]=min((a[i]!=c[k])+dp[i+1][j],
                        (b[j]!=c[k])+dp[i][j+1]);
        }
    }   
    cout<< dp[0][0]<<endl;
    
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}