#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
const int MAX_HEIGHT=20;
vector<vector<int>>up;
vector<int>arr;
vector<int>len;
vector<int>visited;

void dfs(int node){
    if(visited[node]) return;
    visited[node]=true;
    dfs(arr[node]);
    up[node][0]=arr[node];

    len[node]=len[up[node][0]]+1;

    for(int level=1;level<MAX_HEIGHT;level++){
        up[node][level]=up[up[node][level-1]][level-1];
    }

}
int jump(int a,int dis){
    if(dis<0) return -1;
    for(int level=0;level<MAX_HEIGHT;level++){
        if(dis&(1<<level)){
            a=up[a][level];
        }
    }
    return a;
}

void solve() {
    int n,q;
    cin>>n>>q;
    arr.resize(n+1);
    up.assign(n+1,vector<int>(MAX_HEIGHT));
    len.assign(n+1,0);
    visited.assign(n+1,false);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        int cycle_entry_a=jump(a,len[a]);
        int answer;
        if(jump(a,len[a]-len[b])==b){
            answer=len[a]-len[b];
        }

        else if(jump(cycle_entry_a,len[cycle_entry_a]-len[b])==b){
            answer=(len[cycle_entry_a]-len[b])+len[a];
        }
        else{
            answer=-1;
        }
        cout<<answer<<endl;
    }

}

signed main() {
    fastio
    solve();
}