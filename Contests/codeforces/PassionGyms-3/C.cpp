#include <bits/stdc++.h>

using i64 = long long;

const int MXN = (int)1e5+3;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

std::vector<int> g[MXN];
bool vis[MXN];
std::map<std::pair<int,int>, i64> e;
int tin[MXN];
i64 ans = -1;

void dfs(int u, int p, int curT) {
    tin[u] = curT;
    vis[u] = true;
    for (auto v: g[u]) {
        if (vis[v]) {
            if (tin[u] - tin[v] + 1 == 3) {
                std::array<int, 3> vec = {u, v, p};
                std::sort(vec.begin(), vec.end());
                int a = vec[0], b = vec[1], c = vec[2];
                ans = std::max(ans, e[{a,b}] + e[{b,c}] + e[{a,c}]);
            }
        } else dfs(v, u, curT + 1);
    }
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, m;   std::cin >> n >> m;

    for (int i = 0, u, v; i < m; i++) {
        i64 w;
        std::cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        int a = std::min(u,v);
        int b = std::max(u,v);
        e[{a,b}] = w;
    }

    dfs(1, 1, 0);

    return std::cout << ans, 0;
}
