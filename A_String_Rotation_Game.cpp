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
    int ans=0;
    for(int i=0;i<n;i++){
        int j=i+1;
        while(j%n!=i){
            int cnt=0;
            int idx=j%i;
            int prev=(idx-1+n)%n;
            if(s[prev]!=s[idx]){
                cnt++;
                ans=max(ans,cnt);
            }
            j++;
        }
    }
    cout<<ans<<endl;

}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}