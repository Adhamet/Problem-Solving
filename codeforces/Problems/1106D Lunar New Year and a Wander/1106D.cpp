#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<bool> vis(n);
	vector<vector<int>> graph(n, vector<int>());
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		u -= 1, v -= 1;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	set<int> st;
	st.insert(0);
	while (st.size()) {
		int node = *st.begin();
		st.erase(st.begin());
		vis[node] = true;

		cout << node + 1 << ' ';
		for (auto child: graph[node]) {
			if (!vis[child]) st.insert(child);
		}
	}

	return 0;
}
