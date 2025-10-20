#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXN = 2e5+5;

std::vector<int> par;
std::vector<std::vector<int>> g(MXN);

void dfs(int u, int p) {
	par[u] = p;
	for (auto ch: g[u]) if (ch != p) dfs(ch, u);
}

void solve() {
	int n;	std::cin >> n;
	par.assign(n + 1, 0);
	for (int i = 1; i <= n; ++i) g[i].clear();
	for (int i = 1, u, v; i <= n - 1; ++i) {
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0);
	std::vector<bool> onPath(n+2, false);
	for (int node = n; node != 1; node = par[node])
		onPath[node] = true;
	onPath[1] = true;

	int node = 1;
	std::vector<std::pair<int,int>> output;
	while (node != n) {
		int next;
		for (auto ch: g[node]) {
			if (!onPath[ch]) output.push_back({2, ch});
			else next = ch;
		}
		output.push_back({1,-1});
		node = next;
	}

	std::cout << (int)output.size() << '\n';
	for (auto o: output) {
		if (o.first == 1) std::cout << 1 << '\n';
		else std::cout << 2 << ' ' << o.second << '\n';
	}
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
