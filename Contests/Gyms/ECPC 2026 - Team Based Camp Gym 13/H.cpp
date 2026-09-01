#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

const int MXN = (int)1e5 + 2;

int n, m, l, k, ans;
std::vector<std::pair<int,int>> g[MXN];

std::vector<int> path;

void dfs(int u, int len) {
    if (len == k) {
        std::sort(path.begin(), path.end());
        ans = std::max(ans, path[k-1]);
        return;
    }

    for (auto& [v,w]: g[u]) {
        path.push_back(w);
        dfs(v, len + 1);
        path.pop_back();
    }
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    std::freopen("path.in", "r", stdin);

    int t;  std::cin >> t;
    while (t--) {
        ans = 0;

        int start;
        std::cin >> n >> m >> start >> l >> k;
        start--;

        path.clear();
        for (int i = 0; i < n; i++) g[i].clear();

        for (int i = 0; i < m; i++) {
            int u, v, w;
            std::cin >> u >> v >> w;
            u--, v--;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        dfs(start, 0);
        std::cout << ans << '\n';
    }

    return 0;
}
