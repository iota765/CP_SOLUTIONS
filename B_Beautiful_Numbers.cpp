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
    ///// sum of digits of number should be between (1,9)
    vector<int>temp;
    while(n){
        temp.push_back(n%10);
        n/=10;
    }
    int ans=1;
    temp[0]=1;
    sort(temp.begin(),temp.end());
    int i=0;
    vector<int>pre;
    pre[0]=temp[0];
    for(int i=2;i<n;i++){
        pre[i]=pre[i-1]+temp[i];
    }

    int idx=lower_bound(pre.begin(),pre.end(),9)-pre.begin();
    cout<<1+(n-idx)<<endl;
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}