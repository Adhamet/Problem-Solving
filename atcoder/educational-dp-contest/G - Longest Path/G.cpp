#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

vector<int> memo;
vector<vector<int>> g;
int dfs(int u) {
	int &ret = memo[u];
	if (~ret) return ret;
	ret = 0;
	for (auto& v: g[u]) ret = max(1 + dfs(v), ret);
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	g.assign(n, vector<int>());
	memo.resize(n, -1);
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
	}

	int mx = 0;
	for (int i = 0; i < n; ++i) if (memo[i] == -1) mx = max(mx, dfs(i));
	return cout << mx, 0;
}
