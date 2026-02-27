#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
const int LOG=31;
vector<vector<int>>up;
template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}
void build(vector<int>&parents){
    int n=parents.size();
    up.assign(LOG,vector<int>(n));
    for(int j=0;j<n;j++){
        up[0][j]=parents[j];
    }
    for(int i=1;i<LOG;i++){
        for(int j=0;j<n;j++){
            up[i][j]=up[i-1][up[i-1][j]];
        }
    } 
}

int query(int start,int jumps){
    int current=start;
    for(int i=0;i<LOG;i++){
        if(jumps&(1<<i)){
            current=up[i][current];
        }
    }
    return current;
}

void solve() {
    int n,q;
    cin>>n>>q;
    vector<int>parents(n);
    for(int i=0;i<n;i++){
        cin>>parents[i];
        parents[i]--;
    }
    build(parents);
    for(int i=0;i<q;i++){
        int start,jumps;
        cin>>start>>jumps; 
        start--; 
        int ans=query(start,jumps);
        cout<<ans+1<<endl;
    }

}

signed main() {
    // fastio
    solve();
}