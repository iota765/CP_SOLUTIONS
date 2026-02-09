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
    int n,k;
    cin>>n>>k;
    vector<string>strips(k);
    cin>>strips;
    vector<int>fac;
    fac.push_back(1);
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            fac.push_back(i);
        }
        if(i!=n/i){
            fac.push_back(n/i);
        }
    }

    sort(fac.begin(),fac.end());
    vector<vector<int>>present(n,vector<int>(26,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int c=strips[j][i]-'a';
            present[i][c]=1;
    }
}

    string ans;
    for(int d:fac){
        bool ok=true;
        string base(d,'?');
        for(int r=0;r<d and ok;r++){
            vector<int>freq(26,0);
            int cnt=0;
            for(int i=r;i<n;i+=d){
                cnt++;
                for(int c=0;c<26;c++){
                    if(present[i][c]){
                        freq[c]++;
                    }
                }
            }
            bool found=false;
            for(int c=0;c<26;c++){
                if(freq[c]==cnt){
                    base[r]=char('a'+c);
                    found=true;
                    break;
                }
            }
            if(!found) ok=false;
        }
        if(ok){
            ans.clear();
            for(int i=0;i<n;i++){
                ans+=base[i%d];
            }
            break;

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