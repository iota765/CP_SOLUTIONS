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
    vector<int>a(n);
    bool flag=false;
    for(int i=0;i<n;i++){
        int u;
        cin>>u;
        a[i]=u;
        if(u!=0) flag=true;
    }

    if(!flag){
        cout<<"No"<<endl;
        return;
    }
    int mini=*min_element(a.begin(),a.end());
    int maxi=*max_element(a.begin(),a.end());
    int d=maxi-mini;
    
    cout<<"Yes"<<endl;
        vector<int>pos;
    vector<int>neg;
    for(int i=0;i<n;i++){
        if(a[i]>=0) pos.push_back(a[i]);
        else{
            neg.push_back(a[i]);
        }
    }
    vector<int>ans(n);
    int runsum=0;
    for(int i=0;i<n;i++){
        if(runsum<=0 and !pos.empty()){
            ans[i]=pos.back();
            pos.pop_back();
        }
        else{
            ans[i]=neg.back();
            neg.pop_back();
        }
        runsum+=ans[i];
    }
    for(auto ele:ans){
        cout<<ele<<" ";
    }
    cout<<endl;
    
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}