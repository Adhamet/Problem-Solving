#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n+1);
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> par(n+1, -1);
	queue<int> q;
	q.push(1);
	par[1] = 0;

	bool found = false;
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		if (node == n) {
			found = true;
			break;
		}

		for (int child: adj[node]) if (par[child] == -1) {
			par[child] = node;
			q.push(child);
		}
	}

	if (!found) return cout << "IMPOSSIBLE", 0;
	
	vector<int> path;
	for (int i = n; i != 0; i = par[i]) path.push_back(i);
	reverse(path.begin(), path.end());

	cout << (int)path.size() << el;
	for (const int& node: path) cout << node << ' ';
	return 0;
}
