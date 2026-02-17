#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}

int get_root(int x){
    while(x % 2 == 0) x /= 2;
    return x;
}

void solve() {
    int n;
    cin>>n;

    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        if(get_root(i) != get_root(a[i])){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
