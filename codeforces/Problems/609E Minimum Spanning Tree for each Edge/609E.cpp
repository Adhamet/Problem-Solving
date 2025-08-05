#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 2e5 + 5, LOG = 20;

int n, m;
vector<tuple<int, int, int, int>> edges;
vector<pair<int, int>> g[MXN];
bool inMST[MXN];
i64 ans[MXN], mstWeight = 0;
int up[MXN][LOG], mx[MXN][LOG], depth[MXN];

void dfs(int v, int p) {
	for (auto &[u, w]: g[v]) {
		if (u == p) continue;
		up[u][0] = v;
		mx[u][0] = w;
		depth[u] = depth[v] + 1;
		dfs(u, v);
	}
}

int getMax(int a, int b) {
	int res = 0;
	if (depth[a] < depth[b]) swap(a, b);
	int d = depth[a] - depth[b];
	for (int i = 0; i < LOG; ++i)
		if (d >> (i & 1))
			res = max(res, mx[a][i]), a = up[a][i];
	if (a == b) return res;
	for (int i = LOG - 1; i >= 0; --i)
		if (up[a][i] != up[b][i])
			res = max({res, mx[a][i], mx[b][i]}), a = up[a][i], b = up[b][i];
	return max({res, mx[a][0], mx[b][0]});
}

struct DSU {
	vector<int> p;
	DSU(int n) : p(n+1) { iota(p.begin(), p.end(), 0); }
	int find(int x) { return p[x] == x? x: p[x] = find(p[x]); }
	bool unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return 0;
		p[b] = a;
		return 1;
	}
};

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m;
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		edges.emplace_back(w, u, v, i);
	}

	sort(edges.begin(), edges.end());
	DSU dsu(n);

	for (auto &[w, u, v, i] : edges) {
		if (dsu.unite(u, v)) {
			inMST[i] = 1;
			mstWeight += w;
			g[u].emplace_back(v, w);
			g[v].emplace_back(u, w);
		}
	}

	dfs(1, 0);
	for (int j = 1; j < LOG; ++j)
		for (int i = 1; i <= n; ++i)
			up[i][j] = up[up[i][j - 1]][j - 1],
			mx[i][j] = max(mx[i][j - 1], mx[up[i][j - 1]][j - 1]);

	for (auto &[w, u, v, i] : edges) {
		if (inMST[i]) ans[i] = mstWeight;
		else ans[i] = mstWeight + w - getMax(u, v);
	}

	for (int i = 0; i < m; ++i)
		cout << ans[i] << el;
	return 0;
}

