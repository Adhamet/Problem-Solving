#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

void dfs(int node, vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& path) {
	path.push_back(node);
	if (graph[node].empty()) paths.push_back(path);
	else {
		for (int child: graph[node]) {
			dfs(child, graph, paths, path);
		}
	}

	path.pop_back();
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> par(n + 1);
		vector<vector<int>> graph(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> par[i];
			if (par[i] != i) graph[par[i]].push_back(i);
		}

		vector<vector<int>> paths;
		vector<int> path;
		for (int i = 1; i <= n; i++) if (par[i] == i) {
			dfs(i, graph, paths, path);
		}

		vector<bool> vis(n + 1);
		cout << paths.size() << el;
		for (auto p: paths) {
			vector<int> output;
			for (int x: p) {
				if (!vis[x]) output.push_back(x), vis[x] = true;
			}

			cout << output.size() << el;
			for (int num: output) cout << num << " ";
			cout << el;
		}
		cout << el;
	}

	return 0;
}
