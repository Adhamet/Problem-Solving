#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;  std::cin >> n;
    std::vector<std::vector<int>> g(n);
    std::vector<int> deg(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;   std::cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    
    int mxDeg = 0, tot = 0;
    std::vector<int> isSpesh(n, 0);
    for (int i = 0; i < n; i++) {
        mxDeg = std::max(mxDeg, deg[i]);
        if (deg[i] == 3) isSpesh[i] = 1, tot++;
    }
    
    if (mxDeg > 3) return void(std::cout << "NO\n");
    
    bool acc = true;
    std::vector<int> subtreeSpesh(n, 0);
    auto dfs = [&](auto self, int u, int p) -> void {
        subtreeSpesh[u] = isSpesh[u];
        
        int branchesWithSpesh = 0;
        for (int v: g[u]) if (v != p) {
            self(self, v, u);
            subtreeSpesh[u] += subtreeSpesh[v];
            if (subtreeSpesh[v] > 0) branchesWithSpesh++;
        }
        
        if (tot - subtreeSpesh[u] > 0) branchesWithSpesh++;
        if (branchesWithSpesh > 2) acc = false;
    };
    
    dfs(dfs, 0, -1);
    std::cout << (acc? "YES\n": "NO\n");
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t;  std::cin >> t;
    while (t--) solve();
    return 0;
}
