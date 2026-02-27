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
    string s;
    cin>>s;
    int cnt_0=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            cnt_0++;
        }
    }
    int cnt_1=n-cnt_0;
    
    if(cnt_1%2==0){
        cout<<cnt_1<<endl;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cout<<i+1<<" ";
            }
        }
        cout<<endl;
    }
    else if(cnt_0%2==1){
        cout<<cnt_0<<endl;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                cout<<i+1<<endl;
            }
        }
        cout<<endl;
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