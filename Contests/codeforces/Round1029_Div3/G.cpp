#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

// use i64

const int oo = 1e18;
struct DSU {
	vector<int> par, sz, mnW;
	DSU(int n): par(n), sz(n,1), mnW(n,oo) { iota(par.begin(), par.end(), 0); }

	int find(int v) { return v==par[v]? v: par[v] = find(par[v]); }
	bool unite(int u, int v, int w) {
		u = find(u), v = find(v);
		if (u == v) return false;
		if (sz[u] < sz[v]) swap(u,v);
		sz[u]+=sz[v];
		par[v]=u;
		mnW[u] = min({mnW[u], mnW[v], w});
		return true;
	}
};

struct Edge {
	int u, v, w;
	bool operator<(Edge const& other) {
		return w < other.w;
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<Edge> edges;
		for (int i = 0, u, v, w; i < m; ++i) {
			cin >> u >> v >> w;
			u--, v--;
			edges.push_back({u, v, w});
		}

		DSU mst(n);
		int sum = oo;
		sort(edges.begin(), edges.end());
		for (auto& e: edges) {
			mst.unite(e.u, e.v, e.w);
			int r0 = mst.find(0), rn = mst.find(n-1);
			if (r0 == rn) sum = min(sum, e.w + mst.mnW[r0]);
		}

		cout << sum << el;
	}

	return 0;
}
