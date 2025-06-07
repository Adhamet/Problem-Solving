#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	vector<int> par;
	DSU(int n): par(n) { iota(par.begin(), par.end(), 0); }
	int find(int v) { return v == par[v] ? v: par[v] = find(par[v]); }
	bool unite(int u, int v) {
		int U = find(u), V = find(v);
		if (U == V) return false;
		par[V] = U;
		return true;
	}
};

struct Edge {
	int u, v, w;
	bool operator<(const Edge& other) const {
		return w < other.w;
	}
};

vector<vector<int>> g;
void dfs(int v, int V) {
	if (V != -1) cout << v << ' ' << V << el;
	for (auto& vv: g[v]) if (vv != V)
		dfs(vv, v);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m, k, w;
	cin >> n >> m >> k >> w;
	g.resize(k+1);

	char grid[k+1][n][m];
	for (int i = 1; i <= k; ++i)
		for (int j = 0; j < n; ++j)
			for (int l = 0; l < m; ++l)
				cin >> grid[i][j][l];

	vector<Edge> edges;
	for (int i = 0; i <= k; ++i) {
		for (int j = i + 1; j <= k; ++j) {
			if (i == 0) edges.push_back({i, j, n*m});
			else {
				int diff = 0;
				for (int ii = 0; ii < n; ++ii)
					for (int jj = 0; jj < m; ++jj)
						if (grid[i][ii][jj] != grid[j][ii][jj])
							++diff;
				edges.push_back({i, j, diff*w});
			}
		}
	}

	DSU mst(k+1);
	i64 cost = 0;
	sort(edges.begin(), edges.end());
	for (auto& e: edges) if (mst.unite(e.u, e.v)) {
		cost += e.w;
		g[e.u].push_back(e.v);
		g[e.v].push_back(e.u);
	}

	cout << cost << el;
	dfs(0, -1);
	return 0;
}

