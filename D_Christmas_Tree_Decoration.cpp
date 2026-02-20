#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
const int MOD = 998244353;
const int N = 55;
int fact[N];
template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}

int binpow(int a,int b){
    int res=1;
    while(b>0){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}

int inv(int x){
    return binpow(x,MOD-2);
}

void solve() {
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    int total=accumulate(all(a),0LL);
    int k=total/n;
    int z=0;
    bool bad=false;

    for(int i=1;i<=n;i++){
        int used=min(a[i],k);
        a[i]-=used;
        a[0]-=(k-used);
        if(a[0]<0) bad=true;
        if(a[i]>1) bad=true;
        if(a[i]==0) z++;
    }
    if(a[0]>z) bad=true;
    if(bad){
        cout<<0<<endl;
        return;
    }
    int x=z-a[0];
    int ans=fact[z];
    ans=(ans*fact[n-z+a[0]])%MOD;
    ans=(ans*inv(fact[a[0]]))%MOD;
    cout<<ans<<endl;
    
}

signed main() {
    fastio
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    int t; cin >> t;
    while (t--) solve();
    return 0;
}