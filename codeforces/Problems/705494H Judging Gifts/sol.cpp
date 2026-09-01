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

    int t;  std::cin >> t;
    while (t--) {
        int n, m, k, y;
        std::cin >> n >> m >> k >> y;
        y--;

        std::vector<std::pair<int,i64>> g[n];
        for (int i = 0; i < m; i++) {
            int u, v, w;
            std::cin >> u >> v >> w;
            u--, v--;
            g[v].push_back({u, w});
        }

        std::vector<char> col(n, 0);
        std::vector<std::pair<int,int>> cstk;
        bool hasCycle = false;

        cstk.push_back({y, -1});
        col[y] = 1;
        while (!cstk.empty() && !hasCycle) {
            auto &[u, idx] = cstk.back();
            idx++;
            if (idx < (int)g[u].size()) {
                int v = g[u][idx].first;
                if (col[v] == 1) { hasCycle = true; break; }
                if (col[v] == 0) {
                    col[v] = 1;
                    cstk.push_back({v, -1});
                }
            } else {
                col[u] = 2;
                cstk.pop_back();
            }
        }

        if (hasCycle) {
            std::cout << "YES" << '\n';
            continue;
        }

        std::stack<std::pair<int,i64>> stk;
        std::vector<char> vis(n, 0);
        stk.push({y, 0});

        bool acc = false;
        while (!stk.empty()) {
            auto [u, accu] = stk.top();
            stk.pop();

            vis[u] = 1;
            if (accu >= k) {
                acc = true;
                break;
            }

            for (auto [v, w]: g[u]) {
                stk.push({v, accu + w});
            }
        }

        std::cout << (acc? "YES": "NO") << '\n';
    }

    return 0;
}
