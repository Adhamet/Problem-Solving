#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
    vector<int> parent, parity, sz;
    
	DSU(int n) : parent(n), parity(n, 0), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int v) {
		if (v != parent[v]) {
			int pv = parent[v];
            parent[v] = find(parent[v]);
			parity[v] ^= parity[pv];
        }

        return parent[v];
    }
    
    bool unite(int u, int v, int p) {
        int U = find(u), V = find(v);
        if (U == V) return (parity[u] ^ parity[v]) == p;
        if (sz[U] < sz[V]) swap(U, V), swap(u, v);
        parent[V] = U;
        sz[U] += sz[V];
        parity[V] = parity[u] ^ parity[v] ^ p;
        return true;
    }
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    while (cin >> n) {
        if (n == -1) break;

        int m; cin >> m;
		set<int> nodes;
        vector<tuple<int, int, string>> queries;
        for (int i = 0; i < m; ++i) {
            int l, r; string s; cin >> l >> r >> s;
            queries.emplace_back(l, r, s);
            nodes.insert(l - 1);
            nodes.insert(r);
        }

        vector<int> nodesList(nodes.begin(), nodes.end());
        unordered_map<int, int> nodeIdx;
        for (int i = 0; i < (int)nodesList.size(); ++i)
            nodeIdx[nodesList[i]] = i;

        DSU dsu(nodesList.size());
        int ans = m;
        for (int i = 0; i < m; ++i) {
            auto [l, r, s] = queries[i];
            int u = l - 1, v = r, p = (s == "even")? 0: 1;
            int uIdx = nodeIdx[u], vIdx = nodeIdx[v];
            if (!dsu.unite(uIdx, vIdx, p)) {
                ans = i;
                break;
            }
        }

        cout << ans << el;
    }
    return 0;
}
