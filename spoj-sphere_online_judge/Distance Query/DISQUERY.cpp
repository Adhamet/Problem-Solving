#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 1e5+5, LOG = 20, oo = INT_MAX;

int n, timer;
vector<int> tin, tout, dep;
vector<vector<array<int,2>>> g;
vector<vector<int>> up, mnup, mxup;

void dfs(int v, int V, int cw, int depth) {
	tin[v] = ++timer;
	up[v][0] = V;
	dep[v] = depth;
	if (V != -1) 
		mnup[v][0] = cw, mxup[v][0] = cw;
	for (auto &[vv,w]: g[v]) if (vv != V)
		dfs(vv, v, w, depth + 1);
	tout[v] = ++timer;
}

bool isAncestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int __lca(int u, int v) {
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
	dep = vector<int>(n);
	tin = vector<int>(n), tout = vector<int>(n);
	up = vector<vector<int>>(n, vector<int>(LOG, -1));
	mnup = vector<vector<int>>(n, vector<int>(LOG, oo));
	mxup = vector<vector<int>>(n, vector<int>(LOG, -oo));
	g = vector<vector<array<int,2>>>(n);

	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;	cin >> u >> v >> w;
		g[--u].push_back({--v, w});
		g[v].push_back({u, w});
	}

	dfs(0, -1, 0, 0);
	for (int e = 1; e < LOG; ++e) {
		for (int v = 0; v < n; ++v) {
			if (up[v][e - 1] < 0) {
				up[v][e] = -1;
				mnup[v][e] = oo;
				mxup[v][e] = -oo;
			} else {
				up[v][e] = up[up[v][e - 1]][e - 1];
				mnup[v][e] = min(mnup[v][e - 1], mnup[up[v][e - 1]][e - 1]);
				mxup[v][e] = max(mxup[v][e - 1], mxup[up[v][e - 1]][e - 1]);
			}
		}
	}

	int q;	cin >> q;
	while (q--) {
		int u, v;	cin >> u >> v;
		int lc = __lca(--u, --v);

		int mn1 = oo, mx1 = -oo;
		int diff1 = dep[u] - dep[lc];
		int cur = u;
		for (int e = 0; e < LOG; ++e) if ((diff1 & (1 << e))) {
			mn1 = min(mn1, mnup[cur][e]);
			mx1 = max(mx1, mxup[cur][e]);	
			cur = up[cur][e];
		}

		int mn2 = oo, mx2 = -oo;
		int diff2 = dep[v] - dep[lc];
		cur = v;
		for (int e = 0; e < LOG; ++e) if ((diff2 & (1 << e))) {
			mn2 = min(mn2, mnup[cur][e]);
			mx2 = max(mx2, mxup[cur][e]);	
			cur = up[cur][e];
		}

		cout << min(mn1, mn2) << ' ' << max(mx1, mx2) << el;
	}

	return 0;
}
