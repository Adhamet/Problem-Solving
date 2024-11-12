#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long

const int MAXN = 2e4 + 5;
int n, m;
bool vis[MAXN] = {0}, block[MAXN] = {0}, throwout;
vector<ll> adjL[MAXN];
vector<pair<int, int>> node_par;
void dfs(ll node) {
    vis[node] = 1;
    for (auto child: adjL[node]) if (!vis[child]) {
        dfs(child);
    }

    if (adjL[node].size() == 1) {
        throwout = true;
        node_par.push_back({adjL[node][0], node});
        adjL[node].clear();
        block[node] = true;
    }
}

int main() {
    std::ios_base::sync_with_stdio(0), std::cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    int cnt = 0;
    while (true) {
        throwout = false;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) if (!vis[i] && !block[i]) {
            dfs(i);
        }

        for (auto node: node_par) {
            auto itr = find(adjL[node.first].begin(), adjL[node.first].end(), node.second);
            if (itr != adjL[node.first].end()) adjL[node.first].erase(itr);
        }

        if (throwout) cnt += 1;
        else break;
    }
    
    cout << cnt;
    return 0;
}
