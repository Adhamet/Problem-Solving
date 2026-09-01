#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

constexpr int MXN = 12;

int n;
i64 ans = LLONG_MAX;
std::vector<std::pair<int,i64>> g[MXN];
char vis[MXN];

void dfs(int u, int p, i64 accuW) {
    if (u == n - 1) {
        ans = std::min(ans, accuW);
        return;
    }
    
    vis[u] = 1;
    for (auto [v, w]: g[u]) if (!vis[v])
        dfs(v, u, accuW ^ w);
    vis[u] = 0;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    // I guess since N is so small we could do bruteforce
    // DFS, just get to N with xoring Ws, and when we get to N
    // get the minimum result XOR, the only issue is while moving
    // in one path, we need to make sure not to visit what is 
    // already visited, the reason for DFS is to backtrack remove
    // visiteds, I think its feasible
    
    int m;   std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dfs(0, 0, 0);

    return std::cout << ans, 0;
}
