#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
int num_sum(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

void solve() {
    int n;
    cin>>n;
    int ans=0;
    for(int i=n;i<=n+90;i++){
        if(num_sum(i)==i-n){
            ans++;
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