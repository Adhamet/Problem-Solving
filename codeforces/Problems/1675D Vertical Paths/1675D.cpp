#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXN = (int)2e5+5;

int gCol = 1, timer = 0;
int color[MXN], tin[MXN];
std::vector<int> g[MXN];

void dfs(int u, int p, int cCol) {
    color[u] = cCol;
    tin[u] = ++timer;

    for (int i = 0; i < (int)g[u].size(); i++) {
        if (i >= 1) gCol++, cCol = gCol;

        int v = g[u][i];
        if (v == p) continue;

        dfs(v, u, cCol);
    }
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        for (int i = 0; i < n; i++) {
            g[i].clear();
            color[i] = 0;
            tin[i] = 0;
        }

        gCol = 1, timer = 0;

        int root = 0;
        for (int i = 0; i < n; i++) {
            int p;  std::cin >> p;
            p--;
            if (p == i) root = i;
            else g[p].push_back(i);
        }

        dfs(root, -1, 1);

        std::vector<std::vector<int>> paths(gCol + 1);
        for (int i = 0; i < n; i++) {
            paths[color[i]].push_back(i);
        }

        for (int c = 1; c <= gCol; ++c) {
            std::sort(paths[c].begin(), paths[c].end(), [](int a, int b){
                return tin[a] < tin[b];
            });
        }

        std::cout << gCol << '\n';
        for (int c = 1; c <= gCol; c++) {
            std::cout << (int)paths[c].size() << '\n';
            for (auto v: paths[c]) {
                std::cout << (v + 1) << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    return 0;
}

