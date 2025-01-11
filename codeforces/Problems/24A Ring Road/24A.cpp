#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int MAXN = 128;
int edge = 0, cost[MAXN][2];
vector<bool> vis(MAXN);
vector<vector<pair<int, int>>> graph(MAXN);
void dfs(int node, int par) {
    for (auto child : graph[node]) {
        int childnode = child.first, childcost = child.second;
		if (childnode == par || vis[childnode]) continue;
		vis[childnode] = true;
		if (childcost > 0) {
			cost[edge][0] = 0;
			cost[edge][1] = childcost;
		} else {
			cost[edge][0] = -childcost;
			cost[edge][1] = 0;
		}

		edge += 1;
		dfs(childnode, node);
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0, u, v, c; i < n; ++i) {
        cin >> u >> v >> c;
        --u, --v;
        graph[u].emplace_back(v, -c);
        graph[v].emplace_back(u, c);
    }

	dfs(0, -1);
	int dir = 0, rid = 0;
    for (int i = 0; i < edge; ++i) {
        dir += cost[i][0];
        rid += cost[i][1];
    }

    return cout << min(dir, rid), 0;
}
