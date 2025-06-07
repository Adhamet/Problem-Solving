#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	vector<int> par;
	DSU(int n): par(n) { iota(par.begin(), par.end(), 0); }

	int find(int v) { return v == par[v]? v: par[v] = find(par[v]); }
	bool unite(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return false;
		par[v] = u;
		return true;
	}
};

struct Edge {
	int u, v;
	i64 w;
	bool operator<(const Edge& other) {
		return w < other.w;
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	vector<i64> weights(n);
	int mn = 0;
	for (int i = 0; i < n; ++i) {
		cin >> weights[i];
		if (weights[i] < weights[mn]) mn = i;
	}

	vector<Edge> edges;
	for (int i = 0, u, v; i < m; ++i) {
		i64 w;
		cin >> u >> v >> w;
		u--, v--;
		edges.push_back({u, v, w});
	}

	for (int i = 0; i < n; ++i) if (i != mn)
		edges.push_back({mn, i, weights[mn]+weights[i]});

	sort(edges.begin(), edges.end());
	DSU mst(n);
	i64 cost = 0;
	for (auto& e : edges) if (mst.unite(e.u, e.v))
		cost += e.w;
	return cout << cost, 0;
}

