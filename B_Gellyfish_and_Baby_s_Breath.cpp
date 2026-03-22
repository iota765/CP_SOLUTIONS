#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
vector<int>pow2(1e5+1);
const int mod=998244353;
void precompute(){
    pow2[0]=1;
    for(int i=1;i<=100000;i++){
        pow2[i]=(pow2[i-1]*2)%mod;
}

}


void solve() {
    int n;
    cin>>n;
    vector<int>p(n);
    vector<int>q(n);
    for(int i=0;i<n;i++)cin>>p[i];
    for(int i=0;i<n;i++) cin>>q[i];
    vector<int>max_p(n);
    vector<int>max_q(n);
    max_p[0]=0;
    max_q[0]=0;
    for(int i=1;i<n;i++){
        if(p[i]>p[max_p[i-1]]) max_p[i]=i;
        else max_p[i]=max_p[i-1];

        if(q[i]>q[max_q[i-1]]) max_q[i]=i;
        else max_q[i]=max_q[i-1];

    }
    vector<int>ans(n);
    for(int i = 0; i < n; i++){
    int j = max_p[i];
    int k = max_q[i];

    int a1 = p[j], b1 = q[i-j];
    int a2 = p[i-k], b2 = q[k];

    pair<int,int> A = {max(a1,b1), min(a1,b1)};
    pair<int,int> B = {max(a2,b2), min(a2,b2)};

    if(A > B){
        cout << (pow2[a1] + pow2[b1]) % mod << " ";
    } else {
        cout << (pow2[a2] + pow2[b2]) % mod << " ";
    }
} 
    cout<<endl;
}

signed main() {
    fastio
    precompute();
    int t; cin >> t;
    while (t--) solve();
    return 0;
}