#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

const int MAXN = 105;
bool ok = true;
vector<int> colors(MAXN, 0);
vector<vector<int>> graph(MAXN);
void dfs(int node, int col) {
	colors[node] = col;
	for (auto child : graph[node]) {
		if (colors[child] == 0) dfs(child, 3 - col);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int j;
		while (cin >> j && j) graph[i].push_back(j);
	}

	for (int i = 1; i <= n; ++i) {
		if (colors[i] == 0) dfs(i, 1);
	}

	vector<int> team1;
	for (int i = 1; i <= n; ++i) {
		if (colors[i] == 1) team1.push_back(i);
	}

	cout << team1.size() << el;
	for (int member : team1) cout << member << " ";
	cout << el;
	return 0;
}

