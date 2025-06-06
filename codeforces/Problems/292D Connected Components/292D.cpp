#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	int cmp;
	vector<int> par;
	DSU(int n): par(n), cmp(n) { iota(par.begin(), par.end(), 0); }

	int find(int v) { return v==par[v]? v: par[v] = find(par[v]); }
	void unite(int u, int v) {
		int U = find(u), V = find(v);
		if (U != V) {
			par[V] = U;
			cmp -= 1;
		}
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	vector<array<int,2>> edges(m);
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		u -= 1, v -= 1;
		edges[i] = {u,v};
	}

	int k; cin >> k;
	while (k--) {
		int l, r; cin >> l >> r;
		l -= 1, r -= 1;
		DSU dsu(n);
		for (int i = 0; i < l; ++i)
			dsu.unite(edges[i][0], edges[i][1]);
		for (int i = r+1; i < m; ++i)
			dsu.unite(edges[i][0], edges[i][1]);
		cout << dsu.cmp << el;
	}

	return 0;
}
