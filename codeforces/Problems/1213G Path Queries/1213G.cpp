#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	vector<int> par, sz;
	DSU(int n): par(n), sz(n, 1) {
		iota(par.begin(), par.end(), 0);
	}

	int find(int v) { return v == par[v]? v: par[v] = find(par[v]); }
	i64 unite(int u, int v) {
		int U = find(u), V = find(v);
		if (U == V) return 0;
		if (sz[U] < sz[V]) swap(U,V);
		i64 ret = 1LL * sz[U] * sz[V];
		sz[U] += sz[V];
		par[V] = U;
		return ret;
	}
};

struct Edge {
	int u, v;
	i64 w;
	bool operator<(Edge const& other) {
		return w < other.w;
	}
};

const i64 MXE = 2e5+5;
int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	vector<Edge> edges;
	for (int i = 0, u, v; i < n-1; ++i) {
		i64 w;
		cin >> u >> v >> w;
		u--,v--;
		edges.push_back({u,v,w});
	}

	DSU mst(n);
	vector<i64> pref(MXE, 0);
	sort(edges.begin(),edges.end());
	for (auto&e: edges) {
		i64 val = mst.unite(e.u, e.v);
		if (val) pref[e.w] += val;
	}

	for (int i = 1; i < MXE; ++i) pref[i] += pref[i-1];
	for (int i = 0, q; i < m; ++i) {
		cin >> q;
		cout << pref[q] << ' ';
	}

	return 0;
}
