#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

int currsize;
void dfs(int node, unordered_map<int, vector<int>>& graph, map<int, bool>& vis) {
	currsize += 1;
	for (auto& child: graph[node]) if (!vis[child]) {
		vis[child] = true;
		dfs(child, graph, vis);
	}
};

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	set<int> finalSizes;
	int n, totComponents = 0;
	cin >> n;
	finalSizes.insert(n);

	for (int i = 0; i < n; ++i) {
		unordered_map<int, vector<int>> graph;
		map<int, bool> vis;

		int m;
		set<int> currnodes;
		cin >> m;
		for (int j = 0, u, v; j < m; ++j) {
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
			currnodes.insert(u);
			currnodes.insert(v);
		}

		int components = 0;
		vector<int> sizes;
		for (auto &node: currnodes) {
			if (!vis[node]) {
				vis[node] = true;
				currsize = 0;
				dfs(node, graph, vis);
				components += 1;
				sizes.push_back(currsize);
			}
		}

		totComponents = max(components, totComponents);

		sort(sizes.begin(), sizes.end());
		for (auto &sz: sizes) finalSizes.insert(sz);
	}

	cout << totComponents << el;
	if (totComponents == 1) {
		cout << n << el;
	} else if (totComponents == n) {
		for (int i = 0; i < n; ++i) cout << 1 << ' ';
	} else for (auto itr = finalSizes.rbegin(); itr != finalSizes.rend() && totComponents; itr++, totComponents--) cout << *itr << ' ';

	return 0;
}
