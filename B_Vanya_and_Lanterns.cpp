#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
vector<int>a;

void solve() {
    int n,l;
    cin>>n>>l;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    double ans=0;
    sort(a.begin(),a.end());
    ans=max(ans,(double)a[0]);
    ans=max(ans,(double)(l-a[n-1]));
    
    for(int i=0;i<n;i++){
        int d=a[i]-a[i-1];
        ans=max(ans,(a[i]-a[i-1])/2.0);
    }

    cout<<fixed<<setprecision(10)<<ans<<endl;
}

signed main() {
    fastio
    solve();
}