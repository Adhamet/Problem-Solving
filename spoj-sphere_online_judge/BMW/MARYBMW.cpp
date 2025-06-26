#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	vector<int> par, sz;
	DSU(int n): par(n), sz(n, 1) { iota(par.begin(), par.end(), 0); }

	int find(int v) { return v == par[v]? v: par[v] = find(par[v]); }
	void unite(int u, int v) {
		int U = find(u), V = find(v);
		if (U != V) {
			if (sz[U] < sz[V]) swap(U,V);
			sz[U] += sz[V];
			par[V] = U;
		}
	}
};

struct Edge {
	int u, v;
	i64 w;
	bool operator<(Edge const& other) {
		return w > other.w;
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		DSU mst(n);
		vector<Edge> edges;

		for (int i = 0, u, v, w; i < m; ++i) {
			cin >> u >> v >> w;
			edges.push_back({u-1, v-1, w});
		}

		i64 ans = -1;
		sort(edges.begin(), edges.end());
		for (auto& e: edges) {
			mst.unite(e.u, e.v);
			if (mst.find(0) == mst.find(n - 1)) {
				ans = e.w;
				break;
			}
		}

		cout << ans << el;
	}

	return 0;
}
