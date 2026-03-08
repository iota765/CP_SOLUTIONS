#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
const vector<string> tiles = {"abc", "acb", "bac", "bca", "cab", "cba"};

void solve() {
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<vector<int>>pre(6,vector<int>(n,0));
    for(int j=0;j<6;j++){
        for(int i=0;i<n;i++){
            if(i!=0){
                pre[j][i]=pre[j][i-1];
            }
            if(s[i]!=tiles[j][i%3]){
                pre[j][i]++;
            }
        }
    }

    while(m--){
        int ans=1e9;
        int l,r;
        cin>>l>>r;
        l--,r--;
        for(int j=0;j<6;j++){
            ans=min(pre[j][r]-(l?pre[j][l-1]:0),ans);
        }
        cout<<ans<<endl;
    }
    

}

signed main() {
    fastio
    solve();
}