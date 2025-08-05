#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define fst first
#define scd second
#define el '\n'

constexpr int MXN = 1e5 + 5, LOG = 18;

int n, m;
int up[MXN][LOG], depth[MXN], tin[MXN], tout[MXN], timer;
vector<int> g[MXN], nodesAtDepth[MXN];

void dfs(int v, int p) {
	up[v][0] = p;
	depth[v] = (p == v ? 0 : depth[p] + 1);
	tin[v] = ++timer;
	for (int u : g[v]) {
		if (u == p) continue;
		dfs(u, v);
	}
	tout[v] = timer;
}

int lift(int v, int k) {
	for (int e = 0; e < LOG; ++e) if (k & (1 << e))
		v = up[v][e];
	return v;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		nodesAtDepth[i].clear();
		depth[i] = tin[i] = tout[i] = 0;
		for (int e = 0; e < LOG; ++e)
			up[i][e] = 0;
	}

	for (int i = 1, p; i <= n; ++i) {
		cin >> p;
		if (p) {
			g[p].push_back(i);
			g[i].push_back(p);
		}
	}

	timer = 0;
	for (int i = 1; i <= n; ++i) if (!up[i][0])
		dfs(i, i);

	for (int e = 1; e < LOG; ++e)
		for (int v = 1; v <= n; ++v)
			up[v][e] = up[up[v][e - 1]][e - 1];

	int maxD = 0;
	for (int v = 1; v <= n; ++v) {
		nodesAtDepth[depth[v]].push_back(tin[v]);
		maxD = max(maxD, depth[v]);
	}

	for (int d = 0; d <= maxD; ++d) 
		sort(nodesAtDepth[d].begin(), nodesAtDepth[d].end());

	cin >> m;
	while (m--) {
		int v, p; cin >> v >> p;

		if (depth[v] < p) {
			cout << 0 << ' ';
			continue;
		}
		int z = lift(v, p);
		auto &vec = nodesAtDepth[depth[v]];
		int l = lower_bound(vec.begin(), vec.end(), tin[z]) - vec.begin();
		int r = upper_bound(vec.begin(), vec.end(), tout[z]) - vec.begin();

		cout << max(0, r - l - 1) << ' ';
	}

	return 0;
}

