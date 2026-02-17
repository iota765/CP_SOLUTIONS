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
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1] or a[i+1]+a[i]==7){
            cnt++;
        }

    }
    cout<<cnt<<endl;

    
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}