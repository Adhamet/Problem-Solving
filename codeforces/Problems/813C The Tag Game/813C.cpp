#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

vector<vector<int>> graph;
void dfs(int node, int par, vector<int>& dist) {
	for (auto child: graph[node]) if (child != par) {
		dist[child] = dist[node] + 1;
		dfs(child, node, dist);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, x;
	cin >> n >> x;
	graph.resize(n + 1);
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		graph[u].push_back(v), graph[v].push_back(u);
	}

	vector<int> distAlice(n + 1), distBob(n + 1);
	dfs(1, -1, distAlice);
	dfs(x, -1, distBob);
	int mn = INT_MAX, moves = 0;

	// Case 1: They reach a vertex at the same time
	for (int i = 1; i <= n; ++i) if (distBob[i] == distAlice[i]) {
		mn = min(mn, distAlice[i]);
	}

	if (mn != INT_MAX) moves = max(moves, mn);

	// Case 2: Bob reaches a vertex before Alice
	for (int i = 1; i <= n; ++i) if (distBob[i] < distAlice[i]) {
		moves = max(moves, distAlice[i]);
	}
	
	return cout << 2 * moves, 0;
}
