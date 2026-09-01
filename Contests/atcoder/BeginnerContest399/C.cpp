#include <bits/stdc++.h>

// -- Don't use with doubles -----------
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
// -------------------------------------
#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

constexpr int MXN = (int)2e5+5;
char vis[MXN];
std::vector<int> g[MXN];

int ans = 0;
void dfs(int u, int p, int &nodes, int &edges) {
    vis[u] = true;
    nodes++;
    for (int v: g[u]) {
        if (!vis[v]) dfs(v, u, nodes, edges);
        edges++;
    }
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, m;   std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) if (!vis[i]) {
        int nodes = 0, edges = 0;
        dfs(i, i, nodes, edges);
        ans += (edges/2) - (nodes - 1);
    }

    return std::cout << ans, 0;
}
