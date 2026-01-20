#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

struct DSU {
    std::vector<int> par, sz;

    DSU(int n): par(n), sz(n, 1) { 
        iota(par.begin(), par.end(), 0);
    }

    int root(int v) { return v == par[v] ? v : par[v] = root(par[v]); }

    bool unite(int u, int v) {
        u = root(u), v = root(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) std::swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) std::cin >> a[i];

        std::vector<std::array<int,3>> edges;
        for (int i = 0; i < n - 1; i++) {
            int w = std::abs(a[i] - a[i+1]);
            edges.push_back({w,i,i+1});
        }

        std::sort(edges.begin(), edges.end(), [](auto a, auto b) {
            return a[0] > b[0];
        });

        DSU mst(n);
        std::vector<i64> diff(n+1, 0);

        for (auto [w, u, v]: edges) {
            int ru = mst.root(u);
            int rv = mst.root(v);
            if (ru != rv) {
                diff[w] += (i64)mst.sz[ru] * mst.sz[rv];
                mst.unite(ru,rv);
            }
        }
        
        for (int w = n - 2; w >= 1; w--) {
            diff[w] += diff[w+1];
        }

        for (int i = 1; i < n; i++) std::cout << diff[i] << ' ';
        std::cout << '\n';
    }

    return 0;
}
