#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		std::vector<std::vector<int>> g(n);
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			i64 x, y;
			std::cin >> u >> v >> x >> y;
			--u; --v;
			if (x > y) {
				g[v].push_back(u);
			} else if (x < y) {
				g[u].push_back(v);
			}
		}

		std::vector<int> topo;
		std::vector<bool> vis(n, false);
		std::function<void(int)> dfs = [&](int u) {
			vis[u] = true;
			for (int v : g[u]) if (!vis[v]) dfs(v);
			topo.push_back(u);
		};

		for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);
		std::reverse(topo.begin(), topo.end());

		std::vector<int> p(n);
		for (int i = 0; i < n; i++) p[topo[i]] = i + 1;
		for (int i = 0; i < n; i++) std::cout << p[i] << ' ';
		std::cout << '\n';
	}

	return 0;
}


