#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const i64 oo = INT64_MAX;

	i64 n, m, t, k, p;	cin >> n >> m >> t >> k >> p;
	vector<bool> pine(n + 1, false);
	for (int i = 0, u; i < p; ++i) {
		cin >> u;
		pine[u - 1] = true;
	}

	vector<vector<pair<int,int>>> g(n);
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		--u, --v;
		g[u].push_back({v, w * 60});
	}

	vector<i64> dist(n, oo);
	priority_queue<array<i64, 2>, vector<array<i64,2>>, greater<array<i64, 2>>> pq;
	dist[0] = 0;
	pq.push({0, 0});

	while (!pq.empty()) {
		i64 d = pq.top()[0], v = pq.top()[1];
		pq.pop();

		if (d > dist[v]) continue;
		for (auto &[vv, w]: g[v]) {
			i64 nd = d + w + (pine[vv]? k: 0);
			if (nd < dist[vv]) {
				dist[vv] = nd;
				pq.push({nd, (i64)vv});
			}
		}
	}

	i64 tt = t * i64(60);
	return cout << (dist[n - 1] > tt? -1: dist[n - 1]), 0;
}
