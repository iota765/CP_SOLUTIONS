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
    vector<int>p(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    vector<int>fixed(n+1,false);
    int ops=0;
    for(int i=1;i<=n;i++){
        int d;
        cin>>d;
        while(!fixed[d]){
            fixed[d]=true;
            ops++;
            d=p[d];
        }
        cout<<ops<<" ";
    } 
    cout<<endl;
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}