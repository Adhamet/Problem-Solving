#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define pii pair<int,int>
#define el '\n'

struct DSU {
    vector<int> par, sz, col;

    DSU(int n): par(n), sz(n, 1), col(n) {
        for (int i = 0; i < n; ++i) par[i] = i;
    }

    int find(int v) {
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }

    void unite(int a, int b) {
        if (col[a] != col[b]) return;
        int A = find(a), B = find(b);
        if (A != B) {
            if (sz[A] < sz[B]) swap(A, B);
            sz[A] += sz[B];
            par[B] = A;
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);

    int n; cin >> n;
    DSU fs(n + 1);

    vector<pii> edges(n - 1);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) cin >> fs.col[i];

    for (auto& e : edges) fs.unite(e.first, e.second);

    set<int> sts;
    for (int i = 1; i <= n; ++i) {
        sts.clear();
        sts.insert(fs.find(i));
        for (int v : g[i]) sts.insert(fs.find(v));
        int sum = 0;
        for (int id : sts) sum += fs.sz[id];
        if (sum == n) {
            cout << "YES" << el << i;
            return 0;
        }
    }

    return cout << "NO", 0;
}

