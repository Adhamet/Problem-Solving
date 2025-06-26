#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	vector<int> par, sz;
	DSU(int n): par(n), sz(n, 1) { iota(par.begin(), par.end(), 0); }

	int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
	i64 unite(int u, int v) {
		int U = find(u), V = find(v);
		if (U == V) return 0;
		if (sz[U] < sz[V]) swap(U, V);
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

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	vector<Edge> edge;
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		u -= 1, v -= 1;
		edge.push_back({u, v, w});
	}

	sort(edge.begin(), edge.end());

	auto check = [&](int k) {
		DSU mst(n);
		for (int i = k; i < m; ++i)
			mst.unite(edge[i].u, edge[i].v);

		int cmpCnt = 0;
		for (int i = 0; i < n; ++i)
			if (mst.par[i] == i) cmpCnt += 1;
		return cmpCnt == 1;
	};

	int l = 0, r = m - n + 1, ans = 0;
	while (l <= r) {
		int md = (l + r) >> 1;
		if (check(md)) ans = md, l = md + 1;
		else r = md - 1;
	}

	i64 sum = 0;
	DSU mst(n);
	vector<Edge> tree;
	for (int i = ans; i < m; ++i) if (mst.unite(edge[i].u, edge[i].v))
		tree.push_back(edge[i]);

	DSU mst2(n);
	reverse(tree.begin(), tree.end());
	for (auto& e: tree) sum += mst2.unite(e.u, e.v) * e.w;
	return cout << sum, 0;
}

