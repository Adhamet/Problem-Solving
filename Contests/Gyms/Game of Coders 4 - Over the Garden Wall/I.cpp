#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;	cin >> n >> m;
	vector<vector<array<int,2>>> g(n+1);
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		--u,--v;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	vector<array<double,2>> dist(n+1, {0.0, 0.0});
	priority_queue<tuple<double,int,int>> pq;
	dist[0][0] = 1.0;
	pq.push({1.0, 0, 0});

	while (!pq.empty()) {
		auto [p, u, used] = pq.top();
		pq.pop();

		for (auto &[v,w]: g[u]) {
			double cp = w/double(100);
			double np = p * cp;
			if (np > dist[v][used]) {
				dist[v][used] = np;
				pq.push({np, v, used});
			}

			if (used == 0) {
				if (p > dist[v][1]) {
					dist[v][1] = p;
					pq.push({p, v, 1});
				}
			}
		}
	}

	double ans = max(dist[n-1][0], dist[n-1][1]) * double(100);
	return cout << fixed << setprecision(6) << ans, 0;
}
