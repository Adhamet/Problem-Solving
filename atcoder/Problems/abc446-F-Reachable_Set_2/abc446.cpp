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

    int n, m;   std::cin >> n >> m;
    std::map<std::pair<int,int>,bool> conn;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;   std::cin >> u >> v;
        if (u == v) continue;
        bool &ref = conn[{u,v}];
        if (ref == true) continue;
        ref = true;
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) std::sort(g[i].begin(), g[i].end());

    std::vector<char> reachable(n+1, 0);
    std::vector<char> unlocked(n+1, 0);
    int toRemove = 0;
    int reachableCnt = 0;

    std::queue<int> q;
    for (int k = 1; k <= n; ++k) {
        if (unlocked[k]) {
            --toRemove;
            if (!reachable[k]) {
                reachable[k] = 1;
                ++reachableCnt;
                q.push(k);
            }
        } else if (k == 1) {
            if (!reachable[1]) {
                reachable[1] = 1;
                ++reachableCnt;
                q.push(1);
            }
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v: g[u]) {
                if (v <= k) {
                    if (!reachable[v]) {
                        reachable[v] = true;
                        ++reachableCnt;
                        q.push(v);
                    }
                } else {
                    if (!unlocked[v]) {
                        unlocked[v] = true;
                        ++toRemove;
                    }
                }
            }
        }
       
        std::cout << ((reachableCnt != k)? -1: toRemove) << '\n';
    }

    return 0;
}
