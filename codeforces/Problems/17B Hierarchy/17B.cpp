#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	vector<int> par;
	DSU(int n): par(n) { iota(par.begin(), par.end(), 0); }

	int find(int v) { return v==par[v]? v: par[v] = find(par[v]); }
	bool unite(int u, int v) {
		int U = find(u), V = find(v);
		if (U == V) return false;
		par[V] = U;
		return true;
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

	int n; cin >> n;
	DSU mst(n);
	vector<int> q(n);
	for (int i = 0; i < n; ++i) cin >> q[i];

	int m; cin >> m;
	vector<Edge> edges;
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		u -= 1, v -= 1;
		edges.push_back({u,v,w});
	}

	i64 cost = 0;
	vector<bool> taken(n, false);
	sort(edges.begin(), edges.end());
	for (auto& e: edges) {
		if (!taken[e.v] && mst.unite(e.u, e.v)) {
			cost += e.w;
			taken[e.v] = true;
		}
	}

	int root = mst.find(0);
	for (int i = 0; i < n; ++i)
		if (i != root && root != mst.find(i))
			return cout << "-1", 0;
	return cout << cost, 0;
}
