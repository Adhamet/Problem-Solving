#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 3e5 + 5, LOG = 19;

int n, q;
int up[MXN][LOG], depth[MXN];
vector<int> g[MXN];

void dfs(int v, int p) {
	up[v][0] = p;
	depth[v] = (v == p? 0 : depth[p] + 1);
	for (int u : g[v]) if (u != p) dfs(u, v);
}

int lift(int v, int k) {
	for (int i = 0; i < LOG; ++i)
		if (k & (1 << i)) v = up[v][i];
	return v;
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	u = lift(u, depth[u] - depth[v]);
	if (u == v) return u;
	for (int i = LOG - 1; i >= 0; --i)
		if (up[u][i] != up[v][i])
			u = up[u][i], v = up[v][i];
	return up[u][0];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 1);
	for (int i = 1; i < LOG; ++i)
		for (int v = 1; v <= n; ++v)
			up[v][i] = up[up[v][i - 1]][i - 1];

	cin >> q;
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		int w = lca(a, b), d = depth[a] + depth[b] - 2 * depth[w];
		if (c >= d) cout << b << el;
		else {
			int da = depth[a] - depth[w];
			if (c <= da) cout << lift(a, c) << el;
			else cout << lift(b, d - c) << el;
		}
	}

	return 0;
}

