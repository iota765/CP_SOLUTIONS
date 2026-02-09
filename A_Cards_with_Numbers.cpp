#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    map<int, vector<int>> ind;

    for(int i = 1; i <= 2*n; i++){
        int x;
        cin >> x;
        ind[x].push_back(i);
    }

    for(auto &p : ind){
        if(p.second.size() & 1){
            cout << -1 << "\n";
            return 0;
        }
    }

    for(auto &p : ind){
        auto &v = p.second;

        for(int j = 0; j + 1 < v.size(); j += 2){
            cout << v[j] << " " << v[j+1] << "\n";
        }
    }

    return 0;
}
