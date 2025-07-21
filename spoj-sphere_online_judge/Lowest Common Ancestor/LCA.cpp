#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 1005, LOG = 7;

int n, timer;
vector<int> tin, tout;
vector<vector<int>> g, up;

void dfs(int v, int V) {
	tin[v] = ++timer;
	up[v][0] = V;
	for (int e = 1; e < LOG; ++e)
		up[v][e] = up[up[v][e - 1]][e - 1];
	for (auto &vv: g[v]) if (vv != V) dfs(vv, v);
	tout[v] = ++timer;
}

int isAncestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (isAncestor(u, v)) return u;
	if (isAncestor(v, u)) return v;
	for (int e = LOG - 1; e >= 0; --e) if (u != -1)
		if (!isAncestor(up[u][e], v)) u = up[u][e];
	return up[u][0];
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tcs;	cin >> tcs;
	for (int tc = 1; tc <= tcs; ++tc) {
		cin >> n;
		g = vector<vector<int>>(n);
		tin = vector<int>(n), tout = vector<int>(n);
		up = vector<vector<int>>(n, vector<int>(LOG, -1));
		timer = 0;

		for (int u = 0; u < n; ++u) {
			int m;	cin >> m;
			while (m--) {
				int v;	cin >> v;
				g[u].push_back(--v);
				g[v].push_back(u);
			}
		}

		dfs(0, 0);
		int q;	cin >> q;
		cout << "Case " << tc << ":\n";
		while (q--) {
			int u, v;	cin >> u >> v;
			cout << lca(--u, --v) + 1 << el;
		}
	}

	return 0;
}
