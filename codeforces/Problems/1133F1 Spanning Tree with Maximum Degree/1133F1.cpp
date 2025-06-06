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
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int mx = 0, n, m; cin >> n >> m;
	vector<int> inDeg(n);
	vector<Edge> edges;
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		u -= 1, v -= 1;
		g[u].push_back(v);
		inDeg[u]+=1;
		g[v].push_back(u);
		inDeg[v]+=1;
		mx = max({mx, inDeg[u], inDeg[v]});
		edges.push_back({u,v});
	}
	
	for (int i = 0; i < n; ++i) if (inDeg[i] == mx) {
		DSU mst(n);
		for (auto& v: g[i]) if (mst.unite(i, v))
			cout << i+1 << ' ' << v+1 << el;
		for (auto& e: edges) if (mst.unite(e.u, e.v))
			cout << e.u+1 << ' ' << e.v+1 << el;
		break;
	}

	return 0;
}
