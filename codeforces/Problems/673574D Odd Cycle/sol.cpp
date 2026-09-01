#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

constexpr int MXN = 2e5+5;

std::vector<int> g[MXN];
int depth[MXN], ans[MXN];
char vis[MXN];

bool dfs(int u, int p, int dep) {
    vis[u] = 1;
    depth[u] = dep;
    bool curCyclic = false;
    
    for (int v: g[u]) {
        if (vis[v]) {
            if (v != p && (depth[u] - depth[v]) % 2 == 0)
                curCyclic = true;
        } else curCyclic |= dfs(v, u, dep+1);
    }

    if (curCyclic) ans[u] = 1;
    return curCyclic;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        
        for (int i = 1; i <= n; ++i) {
            g[i].clear();
            vis[i] = 0;
            ans[i] = 0;
            depth[i] = 0;
        }
        
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            g[u].push_back(v);
        }
        
        for (int i = 1; i <= n; ++i) if (!vis[i])
            dfs(i, 0, 1);
        
        for (int i = 1; i <= n; ++i) std::cout << ans[i];
        std::cout << "\n";
    }

    return 0;
}
