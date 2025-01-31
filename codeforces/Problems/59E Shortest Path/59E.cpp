#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> adj(n + 1);
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	set<array<int, 3>> forbidden;
	for (int i = 0; i < k; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		forbidden.insert({a,b,c});
	}

	vector<vector<int>> par(n+1, vector<int>(n+1, 0));
	queue<array<int, 2>> q;
	q.push({1, -1});

	int prev = -1;
	bool found = false;
	while (!q.empty()) {
		int node = q.front()[0];
		int parent = q.front()[1];
		q.pop();

		for (auto child: adj[node]) {
			if (parent != -1 && forbidden.count({parent, node, child})) continue;

			if (par[node][child] == 0) {
				par[node][child] = parent;
				if (child == n) {
					prev = node;
					found = true;
					break;
				} else q.push({child, node});
			}
		}

		if (found) break;
	}	

	if (!found) return cout << -1, 0;
	vector<int> path = {n, prev};
	int node = prev, child = n;
	while (par[node][child] != -1) {
		int parent = par[node][child];
		path.push_back(parent);
		child = node, node = parent;
	}

	reverse(path.begin(), path.end());
	cout << path.size() - 1 << el;
	for (const auto& ele: path) cout << ele << ' ';
	return 0;
}
