#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, m;   std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;   std::cin >> u >> v;
        u--,v--;
        g[v].push_back(u);
    }

    int Q;  std::cin >> Q;
    std::vector<bool> isReachable(n, false);

    auto runBFS = [&](int node) {
        if (isReachable[node]) return;
        std::queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            isReachable[u] = true;
            for (auto v: g[u]) if (!isReachable[v]) {
                q.push(v);
            }
        }
    };

    while (Q--) {
        int type, node;
        std::cin >> type >> node;
        node--;

        if (type == 1) {
            runBFS(node);    
        } else { // type == 2
            std::cout << (isReachable[node]? "Yes\n": "No\n");
        }
    }

    return 0;
}
