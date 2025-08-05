#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define i64 int64_t
#define int i64
#define el '\n'

const int MXN = 2e5 + 5, LOG = 21, M = 998244353;

int timer = 0;
int up[MXN][LOG], lvl[MXN], in[MXN], out[MXN];
i64 mlt[MXN][LOG];
vector<int> g[MXN];

void dfs(int u, int p, int d) {
	in[u] = ++timer;
	lvl[u] = d;
	up[u][0] = p;
	mlt[u][0] = (int)g[u].size() - 1;
	for (int e = 1; e < LOG; ++e) {
		up[u][e] = up[up[u][e-1]][e-1];
		mlt[u][e] = (mlt[u][e-1] * mlt[up[u][e-1]][e-1]) % M;
	}
	for (auto &v: g[u]) if (v != p) {
		dfs(v, u, d + 1);
	}
	out[u] = ++timer;
}

bool isAncs(int u, int v) { return in[u] <= in[v] && out[u] >= out[v]; }

int getLCA(int u, int v) {
	if (isAncs(u,v)) return u;
	if (isAncs(v,u)) return v;
	for (auto e = LOG-1; e>=0; --e) {
		if (!isAncs(up[u][e],v)) u = up[u][e];
	}
	return up[u][0];
}

i64 go(int u, int k) {
	i64 prod = 1;
	for (int e = LOG-1; e>=0; --e) if (k & (1 << e)) {
		prod = (prod * mlt[u][e]) % M;
		u = up[u][e];
	}
	return prod;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, q;	cin >> n >> q;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;	cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0, 0, 0);
	while (q--) {
		int u, v;	cin >> u >> v;	--u,--v;
		if (isAncs(u, v)) {
			i64 ans = ((int)g[u].size() * go(up[v][0], lvl[up[v][0]] - lvl[u])) % M;
			cout << ans << el;
		} else if (isAncs(v, u)) {
			i64 ans = ((int)g[u].size() * go(up[u][0], lvl[up[u][0]] - lvl[v])) % M;
			cout << ans << el;
		} else {
			int lca = getLCA(u, v);
			i64 a1 = ((int)g[u].size() * go(up[u][0], lvl[up[u][0]] - lvl[lca])) % M;
			i64 a2 = go(up[v][0], lvl[up[v][0]] - lvl[lca] + 1) % M;
			cout << (a1 * a2) % M << el; 
		}
	}

	return 0;
}

