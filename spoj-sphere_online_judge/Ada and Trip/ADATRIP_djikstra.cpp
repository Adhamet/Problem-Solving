#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	const int oo = 1e18+10;
	int n, m, q;
	cin >> n >> m >> q;

	map<pair<int,int>, int> mnEdge;
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		if (u == v) continue;
		if (u > v) swap(u, v);
		pair<int, int> key = {u, v};
		if (!mnEdge.count(key) || w < mnEdge[key]) mnEdge[key] = w;
	}

	vector<vector<array<int, 2>>> g(n);
	for (auto& edge: mnEdge) {
		int u = edge.first.first;
		int v = edge.first.second;
		int w = edge.second;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	vector<int> dist(n);
	auto djikstra = [&](int start) {
		fill(dist.begin(), dist.end(), oo);
		dist[start] = 0;
		priority_queue<array<int, 2>> pq;
		pq.push({0, start});

		while (!pq.empty()) {
			int d = -pq.top()[0], v = pq.top()[1];
			pq.pop();

			if (d > dist[v]) continue;
			for (auto& [u, w]: g[v]) {
				if (dist[u] > dist[v] + w) {
					dist[u] = dist[v] + w;
					pq.push({-dist[u], u});
				}
			}
		}
	};

	while (q--) {
		int query;
		cin >> query;

		djikstra(query);

		int mxDist = -1, cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (dist[i] != oo) {
				if (dist[i] > mxDist) {
					mxDist = dist[i];
					cnt = 1;
				} else if (dist[i] == mxDist) cnt += 1;
			}
		}

		if (mxDist == -1) cout << "0 1\n";
		else cout << mxDist << ' ' << cnt << el;
	}

	return 0;
}
