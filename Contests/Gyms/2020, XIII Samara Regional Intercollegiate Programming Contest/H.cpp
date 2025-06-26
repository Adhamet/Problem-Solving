#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;	cin >> n;
	vector<vector<int>> g(n);
	vector<int> deg(n);
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++, deg[v]++;
	}

	float cnt = 0;
	function<void(int,int)> dfs = [&](int v, int V) {
		bool isLeaf = true;
		for (auto &vv: g[v]) if (vv != V) {
			isLeaf = false;
			dfs(vv, v);
		}

		if (isLeaf) cnt += 1;
	};

	int found = false;
	for (int i = 0; i < n; ++i) if (deg[i] > 1) {
		found = true;
		dfs(i, -1);
		break;
	}

	if (!found) dfs(0, -1);

	return cout << ceil(cnt / 2), 0;
}
