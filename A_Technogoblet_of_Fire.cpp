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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>p(n);
    cin>>p;
    vector<int>s(n);
    cin>>s;
    vector<int>c(k);
    cin>>c;
    vector<int>max_power(m+1,0);
    for(int i=0;i<n;i++){
        int school=s[i];
        max_power[school]=max(max_power[school],p[i]);
    }
    int ans=0;
    for(int i=0;i<k;i++){
        int id=c[i]-1;
        if(p[id]!=max_power[s[id]]){
            ans+=1;
        }
    }
    cout<<ans<<endl;



}

signed main() {
    fastio
    // int t; cin >> t;
    // while (t--) solve();
    // return 0;
    solve();
}