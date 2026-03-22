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
    int n,c,k;
    cin>>n>>c>>k;
    vector<int>a(n);
    cin>>a;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(k>0){
        if(a[i]<c){
            int diff=min(k,c-a[i]);
            c+=diff;
            k-=diff;
            }
        }
        if(a[i]<=c){
            c+=a[i];
        }
    } 
    cout<<c<<endl;

}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}