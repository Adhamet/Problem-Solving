#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

template<typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

const i64 oo = LLONG_MAX / 4;

struct Edge {
    int u, v;
    i64 c;
};

void solve() {
    int n, m;   std::cin >> n >> m;

    std::vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        i64 c;
        std::cin >> u >> v >> c;
        u--, v--;
        edges.push_back({u, v, c});
    }

    std::vector<i64> cur(n), prev(n);

    i64 finAns = oo;
    for (int i = 0; i <= n; i++) {
        std::fill(cur.begin(), cur.end(), oo);

        for (Edge e: edges) {
            if (prev[e.u] != oo && prev[e.u] + e.c < cur[e.v]) {
                cur[e.v] = prev[e.u] + e.c;
            }
        }

        i64 curAns = oo;
        for (int i = 0; i < n; i++) {
            curAns = std::min(curAns, cur[i]);
        }

        char negCycle = 0;
        if (i <= n - 1) {
            finAns = std::min(curAns, finAns);
        } else {
            if (curAns < finAns) negCycle = 1;
        }

        if (negCycle) return void(std::cout << "-inf\n");
        else if (curAns == oo) break;

        std::swap(prev, cur);
    }

    std::cout << finAns << '\n';
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
