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

    map<int,int>mp;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            mp[i]++;
            n/=i;
        }
    }
    if(n!=1){
        mp[n]++;
    }
    int k=1;
    for(auto ele:mp){
        int f=ele.second;
        int num=ele.first;
        k*=num;
    }
    cout<<k<<endl;
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}