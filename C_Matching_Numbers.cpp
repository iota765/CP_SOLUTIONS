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
    if(!(n&1)){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"Yes"<<endl;

    int x=n/2;
    for(int i=1;i<=n;i++){
        if(i<=x){
            cout<<i<<" "<<(i+n+x+1)<<endl;
        }
        else{
            cout<<i<<" "<<(i-x+n)<<endl;
        }
    }
    

}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}