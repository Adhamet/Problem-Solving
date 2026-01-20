#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, m, l;   std::cin >> n >> m >> l;
    i64 s, t;      std::cin >> s >> t;

    std::vector<std::vector<std::pair<int,i64>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        u--,v--;
        g[u].push_back({v,w});
    }

    std::queue<std::tuple<int,int,i64>> q;
    q.push({0,0,0});

    std::set<int> ans;
    while (!q.empty()) {
        auto [node, e, x] = q.front();
        q.pop();

        if (e == l && x >= s && x <= t) ans.insert(node + 1);
        if (e > l || x > t) continue;

        for (auto [ch, w]: g[node]) {
            q.push({ch, e + 1, x + w});
        }
    }

    for (auto x: ans) std::cout << x << ' ';
    return 0;
}
