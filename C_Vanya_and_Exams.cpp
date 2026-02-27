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
    int n,r,avg;
    cin>>n>>r>>avg;
    vector<pair<int,int>>temp;
    int sum=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        sum+=a;
        temp.push_back({b,a});
    }
    int req=avg*n-sum;
    if(req<=0){
        cout<<0<<endl;
        return;
    }
    int ans=0;
    sort(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++){
        int cost=temp[i].first;
        int can=r-temp[i].second;
        if(req-can>0){
            ans+=cost*can;
            req-=can;
        }
        else{
            ans+=cost*(min(req,can));
            break;
        }
    }
    cout<<ans<<endl;

}

signed main() {
    fastio
    solve();
}