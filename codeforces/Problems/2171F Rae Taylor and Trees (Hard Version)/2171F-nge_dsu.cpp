#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    std::vector<int> par, sz;

    DSU(int n): par(n), sz(n, 1) { iota(par.begin(), par.end(), 0); }

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

void solve() {
    int n;  std::cin >> n;
    int p[n], pos[n + 1];
    for (int i = 0; i < n; ++i) std::cin >> p[i], pos[p[i]] = i + 1;

    int pref[n+1], suff[n+1];
    pref[1] = pos[1];
    for (int i = 2; i <= n; ++i) pref[i] = std::min(pref[i - 1], pos[i]);
    suff[n] = pos[n];
    for (int i = n - 1; i >= 1; --i) suff[i] = std::max(suff[i + 1], pos[i]);

    bool acc = true;
    for (int i = 1; i <= n - 1; ++i) acc = (pref[i] > suff[i + 1])? 0: acc;

    if (!acc) return void(std::cout << "No\n");

    int nge[n];
    DSU dsu(n);
    std::stack<int> stk;
    std::set<std::pair<int,int>> edges;
    for (int i = 0; i < n; ++i) {
        if (stk.empty() || p[i] < p[stk.top()]) { // 3 2 1
            stk.push(i);
        } else { // 3 2 1 [5]
            int grpMn = stk.top();

            while (!stk.empty() && p[i] > p[stk.top()]) {
                if (dsu.unite(i, stk.top())) edges.insert({p[stk.top()], p[i]});
                stk.pop();
            }

            stk.push(grpMn);
        }
    }

    std::cout << "Yes\n";
    for (auto &[u, v]: edges) std::cout << u << ' ' << v << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
