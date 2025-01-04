#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

int currNodes, currEdges;
vector<bool> vis;
vector<vector<int>> adjL;
void dfs(int node) {
	vis[node] = true;
	currNodes++;
	for (auto child : adjL[node]) {
		currEdges++;
		if (!vis[child]) dfs(child);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> gov(k);
	for (int i = 0; i < k; ++i) cin >> gov[i];

	vis.assign(n + 1, false);
	adjL.assign(n + 1, vector<int>());
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	int toAdd = n, mxGov = gov[0], mxNodes = 1;
	map<int, pair<int, int>> component;
	for (int i = 0; i < k; ++i) {
		if (!vis[gov[i]]) {
			currNodes = 0;
			currEdges = 0;
			dfs(gov[i]);
			component[gov[i]] = {currNodes, currEdges / 2};
			if (mxNodes < currNodes) {
				mxGov = gov[i];
				mxNodes = currNodes;
			}

			toAdd -= currNodes;
		}
	}

	int aloneEdges = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			currNodes = 0, currEdges = 0;
			dfs(i);
			aloneEdges += (currEdges / 2);
		}
	}

	int ans = 0, addingNodes = toAdd + mxNodes;
	ans += (addingNodes * (addingNodes - 1) / 2) - component[mxGov].second - aloneEdges;
	for (int i = 0; i < k; ++i) {
		if (gov[i] != mxGov) {
			int nodes = component[gov[i]].first;
			int totEdges = nodes * (nodes - 1) / 2;
			ans += (totEdges - component[gov[i]].second);
		}
	}

	return cout << ans, 0;
}
