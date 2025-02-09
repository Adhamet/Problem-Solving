#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	const int oo = 1e18+10;
	int n;
	vector<vector<array<int, 2>>> g;
	while (cin >> n) {
		if (n == -1) break;
		g.assign(n, vector<array<int, 2>>());

		int m;
		cin >> m;
		vector<tuple<int, int, int>> edges;
		for (int i = 0, u, v, w; i < m; ++i) {
			cin >> u >> v >> w;
			u--, v--;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
			edges.push_back({u, v, w});
		}

		int mnCycle = oo;
		vector<int> bestPath;
		// for each relation between node u and node v
		// try to get from u to v, without any edge u-v
		// because that means if you add that edge, there's a cycle
		// that returns to node u, the starting node.
		for (auto& edge: edges) {
			int uExclude = get<0>(edge);
			int vExclude = get<1>(edge);

			vector<int> dist(n, oo);
			vector<int> par(n, -1);
			priority_queue<array<int, 2>> pq;
			dist[get<0>(edge)] = 0;
			pq.push({0, get<0>(edge)});

			while (!pq.empty()) {
				int d = -pq.top()[0], u = pq.top()[1];
				pq.pop();

				if (u == get<1>(edge)) break;
				if (d > dist[u]) continue;
				
				for (auto& [v, w]: g[u]) {
					if ((u == uExclude && v == vExclude) || (u == vExclude && v == uExclude)) continue;
					if (dist[v] > dist[u] + w) {
						dist[v] = dist[u] + w;
						par[v] = u;
						pq.push({-dist[v], v});
					}
				}
			}

			if (dist[get<1>(edge)] == oo) continue;

			vector<int> path;
			for (int u = get<1>(edge); u != -1; u = par[u]) path.push_back(u);
			reverse(path.begin(), path.end());

			if (path.size() >= 3) {
				int cycleLen = dist[get<1>(edge)] + get<2>(edge);
				if (mnCycle > cycleLen) {
					mnCycle = cycleLen;
					bestPath = path;
				}
			}
		}

		if (mnCycle == oo) cout << "No solution." << el;
		else {
			for (auto& v: bestPath) cout << v + 1 << ' ';
			cout << el;
		}
	}

	return 0;
}
