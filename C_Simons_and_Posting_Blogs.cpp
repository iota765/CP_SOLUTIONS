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
    vector<vector<int>>blogs(n);

    // unordered_set<int>all_users;
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        vector<int>temp(l);
        for (int &x:temp){
            cin>>x;
        }

        reverse(temp.begin(),temp.end());
        unordered_set<int>seen;
        for(int x:temp){
            if(!seen.count(x)){
                blogs[i].push_back(x);
                seen.insert(x);
            }
        }
    }

    vector<int>used(1e6+1,0);
    vector<int>ans;
    vector<int>taken(n,0);
    
    for(int step=0;step<n;step++){
        int best=-1;
        for(int i=0;i<n;i++){
            if(taken[i]) continue;

            if(best==-1 or blogs[i]<blogs[best]){
                best=i;
            }
        }

        for(int x:blogs[best]){
            if(!used[x]){
                ans.push_back(x);
                used[x]=1;
            }
        }
        
        taken[best]=1;

        for(int i=0;i<n;i++){
            if(taken[i]) continue;
            vector<int>filtered;
            for(int x:blogs[i]){
                if(!used[x]){
                    filtered.push_back(x);
                }
                blogs[i]=filtered;
            }
        }
    }

    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
}

signed main() {
    fastio
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
