#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	const int oo = 1e18+10;
	vector<vector<array<int, 2>>> g;
	int t;
	cin >> t;
	while (t--) {
		unordered_map<string, int> cityToIdx;
		int cities;
		cin >> cities;

		int cityIdx = 0;
		g.assign(cities, vector<array<int, 2>>());
		for (int i = 0; i < cities; ++i) {
			string city;
			cin >> city;
			cityToIdx[city] = cityIdx;

			int m;
			cin >> m;
			for (int i = 0, v, w; i < m; ++i) {
				cin >> v >> w;
				v--;
				g[cityIdx].push_back({v, w});
			}

			cityIdx += 1;
		}

		int r; // num of paths to find
		cin >> r;
		string s, t;
		while (r--) {
			cin >> s >> t;
			int start = cityToIdx[s];
			int finish = cityToIdx[t];

			vector<int> dist(cities, oo);
			priority_queue<array<int, 2>> pq;
			dist[start] = 0;
			pq.push({0, start});

			while (!pq.empty()) {
				int d = -pq.top()[0], u = pq.top()[1];
				pq.pop();

				if (u == finish) break;
				if (dist[u] < d) continue;
				
				for (auto& [v, w]: g[u]) {
					if (dist[v] > dist[u] + w) {
						dist[v] = dist[u] + w;
						pq.push({-dist[v], v});
					}
				}
			}

			cout << dist[finish] << el;
		}
	}

	return 0;
}
