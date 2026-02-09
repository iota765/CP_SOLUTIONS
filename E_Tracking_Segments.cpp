#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
int n,m,q;
vector<pair<int,int>>seg;
vector<int>queries;

bool check(int mid){
    vector<int>a(n,0);
    for(int i=0;i<mid;i++){
        a[queries[i]]=1;
    }
    vector<int>pre(n);
    pre[0]=a[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    bool flag=false;
    for(int i=0;i<m;i++){
        int l=seg[i].first;
        int r=seg[i].second;
        int sum=0;
        if(l>0){
            sum=pre[r]-pre[l-1];
        }
        else sum=pre[r];
        if(sum>(r-l+1)/2){
            flag=true;
            break;
        }
    }
    return flag;
}


void solve() {
    cin>>n>>m;
    seg.resize(m);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        seg[i]={l,r};
    }
    cin>>q;
    queries.resize(q);
    for(int i=0;i<q;i++){
        int u;
        cin>>u;
        u--;
        queries[i]=u;
    }
    int low=1,high=q;
    int ans=1e9;
    while(low<=high){
        int mid=low+(high-low)/2;

        if(check(mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(ans==1e9){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}