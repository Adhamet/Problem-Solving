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
		int U = find(u), V = find(v);
		if (U == V) return false;
		par[V] = U;
		return true;
	}
};

struct Edge {
	i64 u, v, w;
	bool operator<(Edge const& other) { return w < other.w; }
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	bool deny = false;
	vector<Edge> edges;
	vector<vector<int>> d(n, vector<int>(n));
	for (i64 i = 0; i < n; ++i) {
		for (i64 j = 0; j < n; ++j) {
			i64 w; cin >> w;
			d[i][j] = w;
			edges.push_back({i, j, w});
			if (i != j && w == 0) deny = true;
			if (i == j && w != 0) deny = true;
		}
	}

	if (deny) return cout << "NO", 0;
	if (n == 1) return cout << "YES", 0;

	vector<vector<array<i64,2>>> graph(n);

	sort(edges.begin(), edges.end());
	DSU mst(n);
	for (auto& e: edges) if (mst.unite(e.u, e.v)) {
		graph[e.u].push_back({e.v, e.w});
		graph[e.v].push_back({e.u, e.w});
	}

	for (int i = 0; i < n; ++i) {
		vector<i64> dd(n, -1);
		queue<int> q;
		dd[i] = 0;
		q.push(i);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (auto [u, w]: graph[v]) {
				if (dd[u] == -1) {
					dd[u] = dd[v] + w;
					q.push(u);
				}
			}
		}

		for (int j = 0; j < n; ++j) if (dd[j] != d[i][j])
			return cout << "NO", 0;
	}

	return cout << "YES", 0;
}
