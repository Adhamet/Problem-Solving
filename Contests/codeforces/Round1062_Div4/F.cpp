#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXN = 2e5+5;

int par[MXN], sz[MXN];
std::vector<std::vector<int>> g(MXN);

void dfs(int u, int p) {
	sz[u] = 1, par[u] = p;
	for (auto ch: g[u]) if (ch != p) {
		dfs(ch,u);
		sz[u] += sz[ch];
	}
}

void solve() {
	int n, k;	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) g[i].clear();
	for (int i = 0, u, v; i < n-1; ++i) {
		std::cin >> u >> v; u--,v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0,-1);

	i64 ans = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		std::vector<int> leftout;
		leftout.push_back(n - sz[i]);
		for (auto ch: g[i]) if (ch != par[i]) leftout.push_back(sz[ch]);
		for (int x: leftout) if (n - x < k) cnt += x;
		ans += n - cnt;
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;	std::cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
