#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(0), std::cin.tie(0);

    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::vector<std::vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            std::cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        std::vector<int> dist(n, -1), childs(n, 0), cnt(n+2, 0);
        std::queue<int> q;
        q.push(0);
        dist[0] = 1;
        cnt[1] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v: g[u]) if (dist[v] == -1) { 
                dist[v] = dist[u] + 1;
                childs[u] += 1;
                cnt[dist[v]] += 1;
                q.push(v);
            }
        }

        int mxDistCnt = 0, mxChilds = 0;
        for (int i = 0; i < n; i++) mxDistCnt = std::max(mxDistCnt, cnt[i]);
        for (int i = 0; i < n; i++) mxChilds = std::max(mxChilds, childs[i]);
        std::cout << std::max(mxDistCnt, mxChilds+1) << '\n';
    }

    return 0;
}
