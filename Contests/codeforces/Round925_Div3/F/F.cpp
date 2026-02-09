#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

static const int MAXN = 200000;

std::vector<int> g[MAXN + 5];
int vis[MAXN + 5];
std::vector<int> topo;
bool cyclic;

void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (vis[v] == 0) {
            dfs(v);
            if (cyclic) return;
        } else if (vis[v] == 1) {
            cyclic = true;
            return;
        }
    }
    vis[u] = 2;
    topo.push_back(u);
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<std::vector<int>> a(k, std::vector<int>(n));

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> a[i][j];
            }
        }

        for (int i = 1; i <= n; i++) {
            g[i].clear();
            vis[i] = 0;
        }
        topo.clear();
        cyclic = false;

        for (int i = 0; i < k; i++) {
            for (int j = 2; j < n; j++) {
                int u = a[i][j - 1];
                int v = a[i][j];
                g[u].push_back(v);
            }
        }

        for (int i = 1; i <= n; i++) {
            std::sort(g[i].begin(), g[i].end());
            g[i].erase(std::unique(g[i].begin(), g[i].end()), g[i].end());
        }

        for (int i = 1; i <= n; i++) if (vis[i] == 0) {
            dfs(i);
            if (cyclic) break;
        }

        // debug(topo.size());
        if (cyclic || (int)topo.size() != n) {
            std::cout << "NO\n";
            continue;
        }

        std::reverse(topo.begin(), topo.end());

        bool ok = true;
        for (int i = 0; i < k && ok; i++) {
            std::vector<int> expected(n);
            expected[0] = a[i][0];
            int idx = 1;

            for (int j = 0; j < n; j++) {
                if (topo[j] != a[i][0]) {
                    expected[idx++] = topo[j];
                }
            }

            for (int j = 0; j < n; j++) {
                if (expected[j] != a[i][j]) {
                    ok = false;
                    break;
                }
            }
        }

        std::cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
