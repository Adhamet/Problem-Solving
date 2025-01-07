#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define ull unsigned long long
#define el '\n'

const int MAXN = 90;
ull cycleCount;
vector<ull> vis(MAXN), par(MAXN);
vector<vector<ull>> adjL;
vector<ull> cycleNodes;
void dfs(ull node, ull parent) {
	if (vis[node] == 2) return;
	vis[node] = 1, par[node] = parent;
	for (auto child : adjL[node]) {
		if (vis[child] == 0) dfs(child, node);
		else if (child != parent && vis[child] == 1) {
			cycleCount += 1;
			ull curr = node;
			ull cycleSize = 1;
			while (curr != child) {
				curr = par[curr];
				cycleSize++;
			}

			cycleNodes.push_back(cycleSize);
		}
	}

	vis[node] = 2;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t, testcase = 1;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cycleCount = 0;
		cycleNodes.clear();
		adjL.assign(n, vector<ull>());
		vis.assign(n, 0), par.assign(n, 0);
		for (int i = 0, u, v; i < m; ++i) {
			cin >> u >> v;
			u -= 1, v -= 1;
			adjL[u].push_back(v);
			adjL[v].push_back(u);
		}

		dfs(0, 0);

		ull ans = 1;
		cout << "Case " << testcase++ << ": ";
		if (cycleCount == 0) {
			cout << ans << el;
			continue;
		}

		for (auto size : cycleNodes) ans *= size;
		cout << ans << el;
	}

	return 0;
}
