#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

constexpr int MXN = (int)1e5+2;

bool vis[MXN];
std::vector<std::pair<int,int>> g[MXN];
i64 a[MXN], cost[MXN], profit[MXN];

void dfs(int u, int p, i64 tc, i64 tp) {
    cost[u] = tc;
    profit[u] = tp;
    for (auto [v, w]: g[u]) if (v != p) {
        dfs(v, u, tc + w, tp + a[v]);
    }
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    for (int i = 0; i < MXN; i++) vis[i] = false;

    int n;
    i64 k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) std::cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v,w});
    }

    dfs(0, 0, 0, a[0]);

    i64 mnCost = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (g[i].empty()) {
            if (cost[i] < mnCost && profit[i] >= k) {
                mnCost = cost[i];
            }
        }
    }

    return std::cout << mnCost, 0;
}
