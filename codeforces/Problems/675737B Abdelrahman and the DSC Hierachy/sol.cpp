#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

constexpr int MXN = (int)1e5+5, MXEXP = 20;
int up[MXN][MXEXP], depth[MXN];
std::vector<std::pair<int,i64>> g[MXN];
i64 A[MXN], profit[MXN], cost[MXN];

void dfs(int u, int p, i64 tp, i64 tc, int d) {
    up[u][0] = p;
    depth[u] = d;
    profit[u] = tp;
    cost[u] = tc;
    for (auto [v, c]: g[u]) if (v != p) {
        dfs(v, u, tp + A[v], tc + c, d + 1);
    }
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, k;   std::cin >> n >> k;
    for (int i = 0; i < n; i++) std::cin >> A[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        i64 c;
        std::cin >> u >> v >> c;
        u--, v--;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    dfs(0, -1, A[0], 0, 0);

    for (int e = 1; e < MXEXP; e++) {
        for (int i = 0; i < n; i++) {
            if (up[i][e-1] == -1) up[i][e] = -1;
            else up[i][e] = up[ up[i][e-1] ][e - 1];
        }
    }

    i64 ans = LLONG_MAX;
    auto lift = [&](int node, int k) {
        for (int e = 0; e < MXEXP; ++e)
            if (up[node][e] != -1 && (k >> e) & 1)
                node = up[node][e];
        return node;
    };

    for (int i = 0; i < n; ++i) {
        int l = 0, r = depth[i], bestAnc = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int anc = lift(i, mid);

            i64 ancProfit = (up[anc][0] == -1? 0LL: profit[up[anc][0]]);

            if (profit[i] - ancProfit >= k) bestAnc = anc, r = mid - 1;
            else l = mid + 1;
        }

        if (bestAnc != -1) {
            ans = std::min(ans, cost[i] - cost[bestAnc]);
        }
    }

    return std::cout << (ans == LLONG_MAX? -1: ans), 0;
}
