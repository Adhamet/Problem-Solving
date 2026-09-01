#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

const int oo = (int)1e9;

int main() {
    std::ios::sync_with_stdio(0), std::cin.tie(nullptr);

    int n, m;   std::cin >> n >> m;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;   std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::queue<std::pair<int,int>> que;
    std::vector<int> dist(n, oo);
    dist[0] = 0;
    que.push({0, 0});

    bool found = 0;
    int k = -1, l = -1;
    while (!que.empty()) {
        auto [cur, par] = que.front();
        que.pop();

        for (int v: g[cur]) {
            if (v == par) continue;
            if (dist[v] != oo) {
                std::cout << dist[cur] + dist[v] + 2 << '\n';
                k = cur, l = v;
                found = 1;
                break;
            }

            dist[v] = dist[cur] + 1;
            que.push({v, cur});
        }

        if (found) break;
    }

    // debug(k, l);
    if (!found) return std::cout << "impossible", 0;

    auto getPath = [&](int p, int q) -> std::vector<int> {
        std::vector<int> path;
        
        while (!que.empty()) que.pop();

        path.push_back(p);
        que.push({p, q});

        while (!que.empty()) {
            auto [cur, par] = que.front();
            que.pop();

            if (dist[cur] == 0) break;

            for (int v: g[cur]) {
                if (v == par) continue;
                if (dist[cur] - dist[v] == 1) {
                    path.push_back(v);
                    que.push({v, cur});
                }
            }
        }

        return path;
    };

    std::vector<int> path1 = getPath(k, l);
    std::vector<int> path2 = getPath(l, k);
    std::reverse(path1.begin(), path1.end());
    for (int x: path1) std::cout << x + 1 << ' ';
    for (int x: path2) std::cout << x + 1 << ' ';
    return 0;
}
