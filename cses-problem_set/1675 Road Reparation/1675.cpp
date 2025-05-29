#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define fst first
#define scd second
#define el '\n'

struct DSU {
	vector<int> par;
	DSU(int n): par(n) { iota(par.begin(), par.end(), 0); }
	
	int find(int v) { return v == par[v]? v: par[v] = find(par[v]); }
	bool isConn(int u, int v) { return find(u) == find(v); }
	void unite(int u, int v) {
		int U = find(u), V = find(v);
		if (U != V) par[V] = U;
	}
};

struct Edge {
	int u, v;
	i64 w;
	bool operator<(Edge const& other) {
		return w < other.w;
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	DSU mst(n);
	vector<Edge> edges;
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		u -= 1, v -= 1;
		edges.push_back({u,v,w});
	}

	i64 cost = 0;
	sort(edges.begin(), edges.end());
	for (auto& e: edges) if (!mst.isConn(e.u, e.v))
		mst.unite(e.u, e.v), cost += e.w;

	int root = mst.find(0);
	for (int i = 0; i < n; ++i)
		if (i != root && mst.find(i) == i) return cout << "IMPOSSIBLE", 0;
	return cout << cost, 0;
}
