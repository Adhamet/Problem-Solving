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
	vector<vector<pair<int, char>>> g(n);
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		u--, v--;
		g[u].push_back({v, 'U'});
		g[v].push_back({u, 'D'});
	}

	int start, end;
	cin >> start >> end;
	start--, end--;

	vector<vector<int>> dist(n, vector<int>(3, oo));
	dist[start][0] = 0;
	priority_queue<tuple<int, int, char>> pq;
	pq.push({0, start, 'S'});

	while (!pq.empty()) {
		int cost = -get<0>(pq.top());
		int v = get<1>(pq.top());
		int currdir = get<2>(pq.top());
		pq.pop();

		if (v == end) return cout << cost, 0;

		int dirIdx;
		if (currdir == 'S') dirIdx = 0;
		else if (currdir == 'U') dirIdx = 1;
		else dirIdx = 2;

		if (dist[v][dirIdx] < cost) continue;

		for (auto& [u, edgedir]: g[v]) {
			int ncost;
			char ndir;

			if (currdir == 'S') ndir = edgedir, ncost = dist[v][dirIdx];
			else {
				if (currdir == edgedir) ndir = edgedir, ncost = dist[v][dirIdx];
				else ndir = edgedir, ncost = dist[v][dirIdx] + 1;
			}

			int ndirIdx = (ndir == 'U')? 1: 2;
			if (ncost < dist[u][ndirIdx]) {
				dist[u][ndirIdx] = ncost;
				pq.push({-ncost, u, ndir});
			}
		}
	}

	return cout << min(dist[end][1], dist[end][2]), 0;
}
