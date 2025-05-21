#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define pii pair<int,int>
#define fst first
#define scd second
#define el '\n'

struct DSU {
    vector<int> par, sz;
    DSU(int n): par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
    bool isConn(int a, int b) { return find(a) == find(b); }
    void unite(int a, int b) {
        int A = find(a), B = find(b);
        if (A != B) {
            if (sz[A] < sz[B]) swap(A, B);
            sz[A] += sz[B];
            par[B] = A;
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n, m;
        i64 k;
        cin >> n >> m >> k;

        vector<array<i64, 3>> edges;
        for (int i = 0; i < m; ++i) {
            int u, v;
            i64 s;
            cin >> u >> v >> s;
            --u, --v;
            edges.push_back({s, u, v});
        }

        sort(edges.begin(), edges.end());

        DSU dsu(n);
        vector<array<i64, 3>> tree;
        for (auto &[c, u, v] : edges) {
            if (!dsu.isConn(u, v)) {
                dsu.unite(u, v);
                tree.push_back({c, u, v});
                if ((int)tree.size() == n - 1) break;
            }
        }

        i64 ans = 0, mxBelowK = 0;
        bool hasOverK = false;
        for (auto &[c, u, v] : tree) {
            if (c >= k) {
                ans += c - k;
                hasOverK = true;
            } else mxBelowK = max(mxBelowK, c);
        }

        if (!hasOverK) {
            i64 closest = INT64_MAX;
            for (auto &[c, u, v] : edges)
                closest = min(closest, abs(c - k));
            ans = min(k - mxBelowK, closest);
        }

        cout << ans << el;
    }

    return 0;
}

