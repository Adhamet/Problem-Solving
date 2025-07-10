#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, a;	cin >> n >> a;
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n-1; ++i) {
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	i64 mx = 0;
	function<void(int,int,int)> dfs = [&](int v, int V, i64 cnt) {
		mx = max(mx, cnt);
		for (auto &vv: g[v]) if (vv != V) {
			dfs(vv, v, cnt + 1);
		}
	};

	a--;
	dfs(a, -1, 0);
	return cout << mx + 1 << el, 0;
}
