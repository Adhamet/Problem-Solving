#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define int i64
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int oo = 1e18;

	int n, m;	cin >> n >> m;
	vector<array<int,3>> edges;
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		--u, --v;
		edges.push_back({u,v,w});
	}

	vector<int> d(n, 0), par(n, -1);
	for (int i = 0; i < n - 1; ++i) {
		bool upd = false;
		for (auto &[v, vv, w]: edges)
			if (d[v] + w < d[vv])
				d[vv] = d[v]+w, upd = true, par[vv] = v;
		if (!upd) break;
	}

	int tortoise = -1;
	for (auto &[v, vv, w]: edges) if (d[v] + w < d[vv]) {
		d[vv] = d[v] + w;
		par[vv] = v;
		tortoise = vv;
	}

	if (tortoise == -1) return cout << "NO", 0;

	for (int i = 0; i < n; ++i) tortoise = par[tortoise];

	vector<int> cyc;
	int cur = tortoise;
	do {
		cyc.push_back(cur);
		cur = par[cur];
	} while (cur != tortoise);
	cyc.push_back(cur);	reverse(cyc.begin(), cyc.end());

	cout << "YES" << el;
	for (auto &x: cyc) cout << x + 1 << ' ';
	return 0;
}
