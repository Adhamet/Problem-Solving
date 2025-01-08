#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int MAXN = 35;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
vector<bool> vis(MAXN, false);
set<pair<int, int>> taken;
vector<pair<int, int>> coords(MAXN);
vector<vector<int>> graph(MAXN);
void dfs(int node, int x, int y, int allowable, int offset) {
	vis[node] = true;
	coords[node] = {x, y};
	taken.insert({x, y});
	int dir = 0;
	for (int child: graph[node]) {
		if (!vis[child]) {
			if (dir == allowable) dir += 1;

			int nx = x + dx[dir] * offset;
			int ny = y + dy[dir] * offset;

			if (!taken.count({nx, ny})) {
				dfs(child, nx, ny, dir ^ 1, offset / 2);
			}

			dir += 1;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		u -= 1, v -= 1;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i < n - 1; ++i) {
		if (graph[i].size() > 4) return cout << "NO", 0;
	}

	dfs(0, 0, 0, -1, 1LL << 32);
	cout << "YES" << el;
	for (int i = 0; i < n; ++i) cout << coords[i].first << " " << coords[i].second << el;
	return 0;
}
