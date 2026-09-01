#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, m;   std::cin >> n >> m;

    std::vector<int> deg(n, 0);
    std::vector<std::array<int,3>> edge;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        deg[u]++, deg[v]++;
        edge.push_back({u, v, w});
    }

    std::vector<std::pair<int,int>> g[n];
    for (auto [u,v,w]: edge) {
        if (deg[u] > deg[v] || (deg[u] == deg[v] && u > v)) std::swap(u,v);
        g[u].push_back({v,w});
    }

    i64 ans = -1;
    std::vector<int> hasCh(n, 0);
    for (int u = 0; u < n; u++) {
        for (auto [v, w]: g[u]) hasCh[v] = w;
        for (auto [v1, w1]: g[u])
            for (auto [v2, w2]: g[v1])
                if (hasCh[v2])
                    ans = std::max(ans, (i64)w1+w2+hasCh[v2]);
        for (auto [v, w]: g[u]) hasCh[v] = 0;
    }

    return std::cout << ans, 0;
}
