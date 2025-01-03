#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int MAXN = 2e5 + 5;
bool ok;
vector<bool> vis(MAXN, false);
vector<vector<int>> adjL(MAXN);
void dfs(int node) {
	if (adjL[node].size() != 2) ok = false;
	vis[node] = true;
	for (auto child: adjL[node]) if (!vis[child]) {
		dfs(child);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) if (!vis[i]) {
		ok = true;
		dfs(i);
		ans += ok;
	}

	return cout << ans, 0;
}
