#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int MAXN = 1e5+5;
int m, ans = 0;
vector<bool> vis(MAXN, false), cats(MAXN, false);
vector<vector<int>> adjL(MAXN);
void dfs(int node, int currM) {
	if (vis[node] || currM > m) return;
	vis[node] = true;

	bool isLeaf = true;
	for (auto child: adjL[node]) if (!vis[child]) {
		isLeaf = false;
		cats[child] ? dfs(child, currM + 1): dfs(child, 0);
	}

	if (isLeaf) ans += 1;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, thereIsCatHere;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> thereIsCatHere;
		cats[i] = (thereIsCatHere == 1);
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u -= 1, v -= 1;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	dfs(0, cats[0] ? 1: 0);
	cout << ans << el;
	return 0;
}
