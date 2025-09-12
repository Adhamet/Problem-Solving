#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n;	std::cin >> n;
	std::vector<std::vector<int>> g(n);
	for (int u = 0, v; u < n; ++u) {
		while (std::cin >> v && v--) g[v].push_back(u);
	}

	std::vector<int> topo, vis(n, false);
	auto dfs = [&](auto &self, int u) -> void {
		vis[u] = true;
		for (auto &v: g[u]) if (!vis[v])
			self(self, v);
		topo.push_back(u);
	};
	for (int u = 0; u < n; ++u) if (!vis[u]) dfs(dfs, u);

	for (auto v: topo) std::cout << v + 1 << ' ';
	return 0;
}
