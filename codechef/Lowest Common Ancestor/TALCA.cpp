#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 2e5+5, LOG = 21;

int n, timer;
int tin[MXN], tout[MXN], depth[MXN];
int up[MXN][LOG];
vector<int> g[MXN];

void dfs(int v, int V, int d) {
	tin[v] = ++timer;
	depth[v] = d;
	up[v][0] = V;
	for (auto &vv: g[v]) if (vv != V)
		dfs(vv, v, d + 1);
	tout[v] = ++timer;
}

bool isAncestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (isAncestor(u, v)) return u;
	if (isAncestor(v, u)) return v;
	for (int e = LOG - 1; e >= 0; --e) if (~up[u][e])
		if (!isAncestor(up[u][e], v)) u = up[u][e];
	return up[u][0];
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	timer = 0;
	for (int node = 0; node < n; ++node) {
		g[node].clear();
		tin[node] = tout[node] = depth[node] = 0;
		for (int e = 0; e < LOG; ++e) up[node][e] = -1;
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v;	cin >> u >> v;
		g[--u].push_back(--v);
		g[v].push_back(u);
	}

	dfs(0, -1, 0);
	for (int e = 1; e < LOG; ++e) {
		for (int v = 0; v < n; ++v) {
			if (up[v][e - 1] == -1) up[v][e] = -1;
			else up[v][e] = up[up[v][e - 1]][e - 1];
		}
	}

	int q;	cin >> q;
	while (q--) {
		int r, u, v;	cin >> r >> u >> v;
		--r, --u, --v;
		cout << max({lca(u, v), lca(u, r), lca(v, r)}) + 1 << el;
	}

	return 0;
}
