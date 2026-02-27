#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
const int LOG=30;
vector<int>arr;
vector<int>visited;
vector<int>dis;
vector<int>dp;
int cycle_start=-1;
int cycle_len=0;
void dfs(int node,int cur_dis){
    if(visited[node]) return;
    visited[node]=true;
    dis[node]=cur_dis;
    int v=arr[node];
    if(!visited[v]){
        dfs(v,cur_dis+1);
    }
    else{
        // we have found a cycle
        if(dp[v]==0){
            cycle_len=dis[node]-dis[v]+1;
            cycle_start=v;
        }
        else{
            cycle_len=dp[v];
        }

    }
    if(cycle_start!=-1){
        dp[node]=cycle_len;
        if(node==cycle_start){
            cycle_start=-1;
        }
    }
    else{
        dp[node]=dp[v]+1;
    }

}

void solve() {
    int n;
    cin>>n;
    arr.resize(n+1);
    visited.resize(n+1,false);
    dp.resize(n+1,0);
    dis.resize(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    } 
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cycle_start=-1;
            cycle_len=0;
            dfs(i,1);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

}

signed main() {
    fastio
    solve();
}