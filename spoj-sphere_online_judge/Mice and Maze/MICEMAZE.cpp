#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	const int oo = 1e18;
	int n, e, t, m;
	cin >> n >> e >> t >> m;
	vector<vector<array<int, 2>>> g(n);
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		--u, --v;
		g[v].push_back({u, w});
	}

	--e;
	vector<int> d(n, oo);
	d[e] = 0;
	priority_queue<array<int, 2>> pq;
	pq.push({0, e}); // time and node

	while (!pq.empty()) {
		int ct = -pq.top()[0], u = pq.top()[1]; 
		pq.pop();
		for (auto& [v, w]: g[u]) if (d[u] + w < d[v]) {
			d[v] = d[u] + w;
			pq.push({-d[v], v});
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) if (d[i] <= t) ++cnt;
	return cout << cnt, 0;
}
