#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int MAXN = 2e5 + 5;
int n, m;
bool bipartite = true;
vector<int> col(MAXN, -1), x(MAXN), y(MAXN);
vector<pair<int, int>> edge(MAXN);
vector<vector<int>> adjL(MAXN, vector<int>());
void dfs(int node, int currCol) {
	col[node] = currCol;
	for (auto child : adjL[node]) {
		if (col[child] == -1) {
			dfs(child, 3 - col[node]);
		} else if (col[node] == col[child]) {
			bipartite = false;
			return;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		u -= 1, v -= 1;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
		x[i] = u, y[i] = v;
	}

	for (int i = 0; i < n; ++i) {
		if (col[i] == -1) dfs(i, 1);
	}

	if (!bipartite) {
		cout << "NO" << el;
		return 0;
	}

	cout << "YES" << el;
	for (int i = 0; i < m; ++i) cout << (col[x[i]] == 1 ? 1 : 0);
	return 0;
}
