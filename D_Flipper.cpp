#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream& operator>>(istream& in, vector<T>& v){
    for(auto &x : v) in >> x;
    return in;
}

void solve(){
    int n;
    cin>>n;
    vector<int>p(n);
    cin>>p;
    int r = 0;
    int best = p[1];

    for (int i = 1; i < n; i++) {
        int val = p[min(n-1, i+1)];
        if (val >=best) {
            best = val;
            r = i;
        }
    }
    vector<int>ans;
    for(int i=r+1;i<n;i++){
        ans.push_back(p[i]);
    }
    ans.push_back(p[r]);

    for(int i=r-1;i>=0;i--){
        if(p[i]>p[0]){
            ans.push_back(p[i]);
        }
        else{
            for(int j=0;j<=i;j++){
                ans.push_back(p[j]);
            }
            break;
        }
    }
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
}