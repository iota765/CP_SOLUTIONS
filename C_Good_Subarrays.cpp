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
    string s;
    cin>>s;
    map<int,int>mp;
    mp[0]++;
    int pre=0;
    for(int i=0;i<n;i++){
        pre+=(s[i]-'0');
        mp[pre-(i+1)]++;
    }
    int ans=0;
    for(auto ele:mp){
        int freq=ele.second;
        ans+=(freq)*(freq-1)/2;
    }
    cout<<ans<<endl;



}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}