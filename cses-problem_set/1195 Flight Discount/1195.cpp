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
		--u, v--;
		g[u].push_back({v, w});
	}

	vector<vector<int>> dist(n, vector<int>(2, oo));
	dist[0][0] = 0;
	priority_queue<array<int, 3>> pq;
	pq.push({0, 0, 0}); // dist, node, using coupon or not

	while (!pq.empty()) {
		int d = -pq.top()[0], v = pq.top()[1], cp = pq.top()[2];
		pq.pop();

		if (d > dist[v][cp]) continue;
		for (auto& [u, w]: g[v]) {
			if (dist[v][cp] + w < dist[u][cp]) {
				dist[u][cp] = dist[v][cp] + w;
				pq.push({-dist[u][cp], u, cp});
			}

			if (cp == 0 && dist[v][cp] + (w/2) < dist[u][1]) {
				dist[u][1] = dist[v][cp] + (w/2);
				pq.push({-dist[u][1], u, 1});
			}
		}
	}

	return cout << min(dist[n - 1][0], dist[n - 1][1]), 0;
}
