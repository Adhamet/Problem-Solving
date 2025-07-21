#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 1005, LOG = 10;

int n;
vector<int> dep;
vector<vector<int>> g, up;

void dfs(int v, int V, int d) {
	dep[v] = d;
	up[v][0] = V;
	for (auto &vv: g[v]) if (vv != V) dfs(vv, v, d + 1);
}

int lift(int v, int k) {
	for (int e = 0; e < LOG && v >= 0; ++e) if (~v)
		if (k & (1 << e)) v = up[v][e];
	return v;
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	u = lift(u, dep[u] - dep[v]);
	if (u == v) return u;
	for (int e = LOG - 1; e >= 0; --e) if (up[u][e] != up[v][e])
		u = up[u][e], v = up[v][e];
	return up[u][0];
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tcs;	cin >> tcs;
	for (int tc = 1; tc <= tcs; ++tc) {
		cin >> n;
		dep = vector<int>(n);
		g = vector<vector<int>>(n);
		up = vector<vector<int>>(n, vector<int>(LOG, -1));

		for (int u = 0; u < n; ++u) {
			int m;	cin >> m;
			while (m--) {
				int v;	cin >> v;
				g[u].push_back(--v);
				g[v].push_back(u);
			}
		}

		dfs(0, -1, 0);
		for (int e = 1; e < LOG; ++e) {
			for (int v = 0; v < n; ++v) {
				int p = up[v][e - 1];
				up[v][e] = (p < 0 ? -1: up[p][e - 1]);
			}
		}

		int q;	cin >> q;
		cout << "Case " << tc << ":\n";
		while (q--) {
			int u, v;	cin >> u >> v;
			cout << lca(--u, --v) + 1 << el;
		}
	}

	return 0;
}

