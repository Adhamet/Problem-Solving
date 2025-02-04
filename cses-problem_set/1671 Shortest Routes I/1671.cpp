#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	const int oo = 1e18+10;
	int n, m;
	cin >> n >> m;
	vector<vector<array<int, 2>>> g(n);
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		u--, v--;
		g[u].push_back({v, w});
	}

	vector<int> dist(n, oo);
	dist[0] = 0;
	priority_queue<array<int, 2>> pq;
	pq.push({0, 0}); // dist, node
	
	while (!pq.empty()) {
		int d = -pq.top()[0], v = pq.top()[1];
		pq.pop();

		if (d > dist[v]) continue;
		for (auto& [u, w]: g[v]) if (dist[v] + w < dist[u]) {
			dist[u] = dist[v] + w;
			pq.push({-dist[u], u});
		}
	}

	for (auto& d: dist) cout << d << ' ';
	return 0;
}
