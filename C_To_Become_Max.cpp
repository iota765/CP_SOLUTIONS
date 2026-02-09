#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
bool is_pos(int mid,vector<int>&a,int k){
    int n=a.size();
    int need=mid;
    for(int i=0;i<n;i++){
        int cost=0;
        for(int j=i,y=mid;j<n;j++,y--){
            if(a[j]>=y) break;
            if(j==n-1) cost+=(int)1e9;
            else cost+=(y-a[j]);
        }
        if(cost<=k) return true;
    }
    return false;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    cin>>a;
    int low=*max_element(a.begin(),a.end());
    int high=low+k;
    int ans=low;
    while(low<=high){
        int mid=(low+high)/2;
        if(is_pos(mid,a,k)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
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