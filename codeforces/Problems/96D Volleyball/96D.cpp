#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr i64 oo = 4e18;

	int n, m;	cin >> n >> m;
	int x, y;	cin >> x >> y;
	--x, --y;

	vector<vector<i64>> d(n, vector<i64>(n, oo));
	for (int i = 0; i < n; ++i) d[i][i] = 0;
	for (int i = 0; i < m; ++i) {
		int u, v;
		i64 w;	cin >> u >> v >> w;
		--u, --v;
		d[u][v] = min(d[u][v], w);
		d[v][u] = min(d[v][u], w);
	}

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	vector<i64> t(n), c(n);
	for (int i = 0; i < n; ++i) cin >> t[i] >> c[i];

	vector<vector<pair<int,i64>>> g(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i!=j && d[i][j] <= t[i]) 
				g[i].push_back({j, c[i]});

	vector<i64> bd(n, oo);
	bd[x] = 0;
	priority_queue<pair<i64,int>, vector<pair<i64,int>>, greater<>> pq;
	pq.push({0, x});
	
	while (!pq.empty()) {
		auto [d, u] = pq.top();		pq.pop();
		
		if (d > bd[u] || u == y) continue;
		for (auto &e: g[u]) {
			int v = e.first;
			i64 w = e.second;
			if (d + w < bd[v]) {
				bd[v] = d + w;
				pq.push({bd[v], v});
			}
		}
	}

	return cout << (bd[y] == oo? -1: bd[y]), 0;
}
