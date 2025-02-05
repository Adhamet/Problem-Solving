#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m, s, t;
	cin >> n >> m >> s >> t;
	s--, t--;

	set<array<int, 2>> exists;
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		--u, --v;
		if (u > v) swap(u, v);
		exists.insert({u, v});
		g[u].push_back(v);
		g[v].push_back(u);
	}

	auto bfs = [&](int start, vector<int>& d) {
		queue<int> q;
		q.push(start);
		d[start] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (auto& v: g[u]) if (d[v] == -1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	};

	vector<int> dS(n, -1), dT(n, -1);
	bfs(s, dS), bfs(t, dT);

	int dist = dS[t], cnt = 0;
	for (int u = 0; u < n; ++u) {
		for (int v = u + 1; v < n; ++v) {
			if (exists.count({u, v})) continue;
			if (dS[u] + 1 + dT[v] >= dist && dS[v] + 1 + dT[u] >= dist) cnt += 1;
		}
	}

	return cout << cnt, 0;
}
