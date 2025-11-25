#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXN = 2e5+5;

bool alive[MXN], col[MXN];
int par[MXN], deg[MXN];
std::vector<std::vector<int>> g(MXN);

void dfs(int u, int p, bool c) {
	par[u] = p;
	col[u] = c;
	for (auto ch: g[u]) if (ch != p) dfs(ch, u, !c);
}

void solve() {
	int n;	std::cin >> n;
	for (int i = 1; i <= n; ++i) g[i].clear(), alive[i] = true;
	for (int i = 1, u, v; i <= n - 1; ++i) {
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0, 0);

	std::queue<int> q[2];
	for (int i = 1; i <= n; ++i) {
		deg[i] = (int)g[i].size();
		if (i != n && deg[i] == 1) q[col[i]].push(i);
	}

	std::vector<std::pair<int,int>> ops;
	int del = 0;
	bool parity = col[1];

	while (del < n - 1) {
		bool curCol;
		if (q[0].empty() && q[1].empty()) break;
		else if (q[0].empty()) curCol = 1;
		else curCol = 0;
		
		int v = q[curCol].front();	q[curCol].pop();
		if (!alive[v]) continue;

		if (parity == col[v]) ops.push_back({1,0}), parity ^= 1;
		else ops.push_back({1,0}), ops.push_back({1,0});
		ops.push_back({2,v});
		alive[v] = 0;
		++del;

		for (int ch: g[v]) {
			if (!alive[ch]) continue;
			deg[ch]--;
			if (ch != n && deg[ch] == 1) q[col[ch]].push(ch);
		}
	}

	std::cout << (int)ops.size() << '\n';
	for (auto &op: ops) {
		if (op.first == 1) std::cout << "1\n";
		else std::cout << "2 " << op.second << '\n';
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
