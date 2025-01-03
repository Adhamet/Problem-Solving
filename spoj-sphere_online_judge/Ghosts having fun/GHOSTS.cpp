#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

vector<bool> vis;
bitset<1001> mask[1001];
vector<vector<int>> adjL;
void dfs(int node) {
	vis[node] = true;
	for (auto child: adjL[node]) {
		if (!vis[child]) dfs(child);
		mask[node] |= mask[child];
		mask[node].set(child);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, k;
	cin >> n >> k;
	adjL.assign(n + 1, vector<int>());

	for (int i = 0, u, v; i < k; ++i) {
		cin >> u >> v;
		if (mask[v][u] || u == v) cout << u << " " << v << el;
		else if (mask[u][v]) continue;
		else {
			adjL[u].push_back(v);
			vis.assign(n + 1, false);
			for (int i = 1; i <= n; ++i) if (!vis[i]) {
				dfs(i);
			}
		}
	}

	return cout << "0 0", 0;
}
