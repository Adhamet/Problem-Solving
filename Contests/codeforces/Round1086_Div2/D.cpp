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

    // since this is a tree we can skip some test cases
    // one of them which have too many edges
    // (making it not a tree) or too few edges 
    // (make it different connected components) 
    // also each node u should reach u if that isnt there
    // too its also a skip, after we've done that we have limited
    // our chances, so for a node u we could check all of its
    // reachables to it, if its the second most reachble it should
    // be linked to it, otherwise if its the only
    // reachable to it we also link to it and we keep doing that
    // until we finish

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<std::string> s(n);
        for (int i = 0; i < n; i++) std::cin >> s[i];

        bool acc = true;
        for (int i = 0; i < n; i++) {
            if (s[i][i] == '0') {
                std::cout << "No\n";
                acc = false;
                break;
            }
        }

        if (!acc) continue;

        std::vector<std::pair<int, int>> edges;
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (u != v && s[u][v] == '1') {
                    bool onlyOne = true;
                    for (int w = 0; w < n; w++) {
                        if (w != u && w != v && s[u][w] == '1' && s[w][v] == '1') {
                            onlyOne = false;
                            break;
                        }
                    }
                    
                    if (onlyOne) edges.push_back({u, v});
                }
            }
        }

        if ((int)edges.size() != n - 1) {
            std::cout << "No\n";
            continue;
        }

        std::vector<std::vector<int>> dg(n);
        for (auto& ed : edges) dg[ed.first].push_back(ed.second);
        
        std::vector<std::string> reach(n, std::string(n, '0'));
        for (int i = 0; i < n; i++) reach[i][i] = '1';
        for (int i = 0; i < n; i++) {
            std::queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v: dg[u]) {
                    if (reach[i][v] == '0') {
                        reach[i][v] = '1';
                        q.push(v);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (reach[i] != s[i]) {
                acc = false;
                break;
            }
        }
        if (!acc) {
            std::cout << "No\n";
            continue;
        }

        // EDGE VALIDITY CYCLES AND CNT
        std::vector<std::vector<int>> ug(n);
        for (auto &ed: edges) {
            ug[ed.first].push_back(ed.second);
            ug[ed.second].push_back(ed.first);
        }

        std::vector<char> vis(n, 0);
        std::queue<std::pair<int,int>> q;
        q.push({0,0});
        vis[0] = 1;
        int visCnt = 0;
        bool cycle = false;

        while (!q.empty()) {
            auto [u, p] = q.front();
            q.pop();
            visCnt++;

            for (int v: ug[u]) {
                if (!vis[v]) vis[v] = 1, q.push({v, u});
                else if (v != p) cycle = true;
            }
        }

        if (cycle || visCnt != n) {
            std::cout << "No\n";
            continue;
        }

        std::cout << "Yes\n";
        for (auto& ed : edges) std::cout << ed.first + 1 << " " << ed.second + 1 << "\n";
    }
    
    return 0;
}
