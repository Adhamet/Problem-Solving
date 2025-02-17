#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    vector<int> ans(n, 0);
    int minNode = 0;
    for (int i = 1; i < n; ++i) {
        if ((int)g[i].size() < (int)g[minNode].size()) {
            minNode = i;
        }
    }

    unordered_set<int> blocked;
    blocked.insert(minNode);
    for (auto &v: g[minNode]) blocked.insert(v);

    for (int i = 0; i < n; ++i) if (!blocked.count(i)) ans[i] = 1;

    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
    return 0;
}