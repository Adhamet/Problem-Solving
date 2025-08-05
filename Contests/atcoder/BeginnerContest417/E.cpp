#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, m, x, y;	cin >> n >> m >> x >> y;

		vector<vector<int>> g(n);
		for (int i = 0; i < m; ++i) {
			int u, v;	cin >> u >> v;
			--u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		for (auto &vec: g) sort(vec.begin(), vec.end());
		
		vector<int> par(n, -1);
		vector<bool> vis(n, false);
		x--, y--;
		function<bool(int)> dfs = [&](int u) -> bool {
			if (u == y) return true;
			vis[u] = true;
			for (auto &v: g[u]) if (!vis[v]) {
				par[v] = u;
				if (dfs(v)) return true;
			}
			return false;
		};

		dfs(x);
		vector<int> path;
		path.push_back(y);
		for (int v = par[y]; v != -1; v = par[v])
			path.push_back(v);
		reverse(path.begin(), path.end());
		for (auto &x: path) cout << x + 1 << ' ';
		cout << el;
	}

	return 0;
}
