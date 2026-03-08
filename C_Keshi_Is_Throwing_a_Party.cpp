#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
vector<int>rich;
vector<int>poor;
int n;
bool is_poss(int mid){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(poor[i]>=cnt and rich[i]>=mid-cnt-1){
            cnt++;
        }
    }
    return cnt>=mid;
}

void solve() {
    cin>>n;
    rich.resize(n);
    poor.resize(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        rich[i]=a;
        poor[i]=b;
    }
    int low=1;
    int high=n;
    int ans=0;
    while(low<=high){
        int mid=(high+low)/2;
        if(is_poss(mid)){
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