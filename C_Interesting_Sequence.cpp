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
    int n,x;
    cin>>n>>x;
    if(x>n){
        cout<<-1<<endl;
        return;
    }
    if(x==n){
        cout<<n<<endl;
        return;
    }
    if((n&x)!=x){
        cout<<-1<<endl;
        return;
    }
    int highest_diff_bit=-1;
    for(int i=62;i>=0;i--){
        if(((n>>i)&1)!=((x>>i)&1)){
            highest_diff_bit=i;
            break;
        }
    }
    int m=((n>>(highest_diff_bit+1))+1)<<(highest_diff_bit+1);
    if((n&m)==x){
        cout<<m<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}