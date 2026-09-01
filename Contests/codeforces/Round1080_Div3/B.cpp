#include <bits/stdc++.h>

using i64 = long long;

const int MXN = 2e5 + 5;

std::vector<int> g[MXN];
bool vis[MXN];
int a[MXN];

std::vector<int> compIdx, compVal;

void dfs(int u) {
    vis[u] = true;
    compIdx.push_back(u);
    compVal.push_back(a[u]);
    for (int v: g[u]) if (!vis[v])
        dfs(v);
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;

        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            g[i].clear();
            vis[i] = false;
        }

        for (int i = 1; i <= n; i++) {
            if (2*i <= n) {
                g[i].push_back(2*i);
                g[2*i].push_back(i);
            }
        }

        bool acc = true;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;

            compIdx.clear();
            compVal.clear();

            dfs(i);
            std::sort(compIdx.begin(), compIdx.end());
            std::sort(compVal.begin(), compVal.end());
            if (compIdx != compVal) {
                acc = false;
                break;
            }
        }

        std::cout << (acc ? "YES\n" : "NO\n");
    }

    return 0;
}

