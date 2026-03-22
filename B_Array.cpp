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
    vector<int>a(n);
    cin>>a;
    vector<int>ans;
    for(int i=0;i<n;i++){
        int cnt1=0,cnt2=0;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]) cnt1++;
            else if(a[j]>a[i]) cnt2++;
        }
        ans.push_back(max(cnt1,cnt2));
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}