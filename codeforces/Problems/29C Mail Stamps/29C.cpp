#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

map<int, vector<int>> adjL;
map<int, bool> vis;
vector<int> path;
void dfs(int node) {
    vis[node] = true;
    for (auto child: adjL[node]) if (!vis[child]) dfs(child);
    path.push_back(node);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
 
    for(auto it: adjL) if (it.second.size() == 1) {
        dfs(it.first);
        break;
    }
 
    for(auto node: path) cout << node << " ";
    return 0;
}
