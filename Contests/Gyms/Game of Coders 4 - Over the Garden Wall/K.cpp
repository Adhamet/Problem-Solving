#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define fs first
#define sc second
#define el '\n'

const int MXN = 2e5+5, LOG = 21;

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
	int u, v, w;
	bool operator<(const Edge &other) const {
		return w < other.w;
	}
};

int n, m, up[MXN][LOG], depth[MXN];
i64 weight[MXN];
vector<pair<int,int>> g[MXN];

void dfs(int u, int p) {
	for (auto &[v, w] : g[u]) if (v != p) {
		depth[v] = depth[u] + 1;
		weight[v] = weight[u] + w;
		up[v][0] = u;
		dfs(v, u);
	}
}

int lift(int u, int k) {
	for (int e = 0; e < LOG; ++e)
		if (k & (1 << e)) u = up[u][e];
	return u;
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	u = lift(u, depth[u] - depth[v]);
	if (u == v) return u;
	for (int e = LOG - 1; e >= 0; --e)
		if (up[u][e] != up[v][e])
			u = up[u][e], v = up[v][e];
	return up[u][0];
}

i64 actualdist(int u, int v) { return weight[u] + weight[v] - 2 * weight[lca(u, v)]; }

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	vector<Edge> edges;
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		--u, --v;
		edges.push_back({u, v, w});
	}

	DSU mst(n);
	sort(edges.begin(), edges.end());
	for (auto &[u, v, w]: edges) if (mst.unite(u, v)) {
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	depth[0] = 0, up[0][0] = 0, weight[0] = 0;
	dfs(0, -1);
	for (int e = 1; e < LOG; ++e)
		for (int v = 0; v < n; ++v)
			up[v][e] = up[up[v][e-1]][e-1];

	for (auto &[u, v, w]: edges) {
		if (actualdist(u, v) > w) return cout << "NO", 0;
	}

	return cout << "YES", 0;
}
