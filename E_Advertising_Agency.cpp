#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
const int MOD=1e9+7;
const int N=1e6+5;

int fact[N],invfact[N];

int binpow(int a,int b){
    int res=1;
    while(b){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
} 

void precompute(){
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    invfact[N-1]=binpow(fact[N-1],MOD-2);
    for(int i=N-2;i>=0;i--){
        invfact[i]=(invfact[i+1]*(i+1))%MOD;
    }

}

int nCr(int n,int r){
    if(r<0 or r>n) return 0;
    return fact[n]*invfact[r]%MOD*invfact[n-r]%MOD;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    cin>>a;
    sort(a.rbegin(),a.rend());
    int x=a[k-1];
    int total=0,need=0;
    for(int v:a){
        if(v==x) total++; 
    }
    for(int i=0;i<k;i++){
        if(a[i]==x) need++;
    }
    cout<<nCr(total,need)<<endl;
}

signed main() {
    fastio
    precompute();
    int t; cin >> t;
    while (t--) solve();
    return 0;
}