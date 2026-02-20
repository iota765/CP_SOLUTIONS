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
    int a,b;
    cin>>a>>b;
    if((!(a&1) and b&1) or( a&1 and b%4==2)){
        cout<<-1<<endl;
        return;
    }
    else{
        if(b&1){
            cout<<a*b+1<<endl;
            return;
        }
        else{
            cout<<(a*b/2)+2<<endl;
            return;
        }
    }



}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}