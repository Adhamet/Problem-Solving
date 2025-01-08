#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int MAXN = 2e5 + 5;
struct Edge {
	int from, to;
};

vector<Edge> edges;
vector<vector<int>> ans(MAXN), adjL(MAXN);
void dfs(int node, int par, int skipDay) {
	int day = 0;
	for (auto edgeIdx: adjL[node]) {
		Edge edge = edges[edgeIdx];
		int child = (edge.from == node? edge.to: edge.from);

		if (child == par) continue;
		if (day == skipDay) day += 1;
		ans[day].push_back(edgeIdx);
		dfs(child, node, day);
		day += 1;
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		u -= 1, v -= 1;
		edges.push_back({u, v});
		adjL[u].push_back(i);
		adjL[v].push_back(i);
	}

	dfs(0, -1, -1);

	int mxDays = 0;
	for (int i = 0; i < n; ++i) mxDays = max(mxDays, (int)adjL[i].size());
	cout << mxDays << el;
	for (int day = 0; day < mxDays; ++day) {
		cout << ans[day].size() << ' ';
		for (auto x: ans[day]) cout << x + 1 << ' ';
		cout << el;
	}

	return 0;
}
