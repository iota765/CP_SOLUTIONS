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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    int si,sj,ei,ej;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            mat[i][j]=(c=='#')?1:0;
            if(c=='S') si=i,sj=j;
            if(c=='T') ei=i,ej=j;
        }
    }
    struct state{
        int i,j,val;
    };
}

signed main() {
    fastio
    solve();
}