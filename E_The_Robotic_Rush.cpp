#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    string s;
    cin >> s;

    sort(b.begin(), b.end());

    vector<vector<int>> die_at(2*k + 1);

    for(int i=0;i<n;i++){
        int pos = a[i];
        auto it = lower_bound(b.begin(), b.end(), pos);
        if(it != b.end()){
            int disR = *it - pos;
            if(disR <= k)
                die_at[disR + k].push_back(i);
        }
        if(it != b.begin()){
            --it;
            int disL = pos - *it;
            if(disL <= k)
                die_at[-disL + k].push_back(i);
        }
    }

    vector<bool> dead(n, false);
    int alive = n;
    int d = 0;

    for(int i=0;i<k;i++){
        if(s[i] == 'L') d--;
        else d++;

        int idx = d + k;
        if(idx >= 0 && idx < (int)die_at.size()){
            for(int robot : die_at[idx]){
                if(!dead[robot]){
                    dead[robot] = true;
                    alive--;
                }
            }
            die_at[idx]={};
        }
        cout << alive << " ";
    }
    cout << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solve();
}