#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define int i64
#define el '\n'

struct Edge {
	int u, v, w;
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int oo = INT64_MAX;

	int n, m;	cin >> n >> m;
	vector<Edge> edges;
	vector<vector<int>> g(n);
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		--u, --v;
		edges.push_back({u, v, w});
		g[u].push_back(v);
	}

	vector<int> d(n, -oo);		d[0] = 0;
	for (int i = 0; i < n - 1; ++i) {
		bool upd = false;
		for (auto &[v, vv, w]: edges) {
			if (d[v] != -oo && d[v] + w > d[vv]) {
				d[vv] = d[v] + w;
				upd = true;
			}
		}

		if (!upd) break;
	}

	vector<bool> cyc(n, false);
	for (auto &[v, vv, w]: edges) {
		if (d[v] != -oo && d[v] + w > d[vv])
			cyc[vv] = true;
	}

	vector<bool> vis(n, false);
	queue<int> q;
	for (int v = 0; v < n; ++v) if (cyc[v])
		q.push(v), vis[v] = true;

	while (!q.empty()) {
		int v = q.front();	q.pop();
		for (auto &vv: g[v]) if (!vis[vv])
			vis[vv] = true, q.push(vv);
	}

	return cout << (vis[n - 1]? -1: d[n - 1]), 0;
}
