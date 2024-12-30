#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define el '\n'

const int MAXN = 105;
set<pair<int, int>> blocked;
vector<vector<int>> adjL(MAXN);
vector<bool> vis(MAXN, 0);
void dfs(int node, int par) {
	vis[node] = true;
	for (auto child: adjL[node]) {
		pair<int, int> edge = {min(child, node), max(child, node)};
		if (!vis[child]) dfs(child, node);
		else if (!blocked.count(edge) && child != par) blocked.insert(edge);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	char input;
	int n, d, a, valAns = 0;
	cin >> n >> d >> a;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> input;
			if (input == '1') adjL[i].push_back(j);
		}
	}
	
	int compNums = 0;
	vector<int> compRoots;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			compNums += 1;
			compRoots.push_back(i);
			dfs(i, -1);
		}
	}

	vector<vector<char>> ans(n, vector<char>(n, '0'));
	for (auto pr: blocked) {
		valAns += d;
		ans[pr.first][pr.second] = 'd';
		ans[pr.second][pr.first] = 'd';
	}

	for (int i = 0; i < compNums - 1; i++) {
		valAns += a;
		ans[compRoots[i]][compRoots[i + 1]] = 'a';
		ans[compRoots[i + 1]][compRoots[i]] = 'a';
	}

	cout << valAns << el;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << ans[i][j];
		cout << el;
	}

	return 0;
}
