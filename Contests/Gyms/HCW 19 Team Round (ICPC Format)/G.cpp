#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<vector<int>> gb21(n);
	for (int i = 0, u,v; i < n - 1; ++i) {
		cin >> u >> v;
		u--, v--;
		gb21[u].push_back(v);
		gb21[v].push_back(u);
	}

	int m; cin >> m;
	vector<vector<int>> lowie(m);
	for (int i = 0, u,v; i < m - 1; ++i) {
		cin >> u >> v;
		u--, v--;
		lowie[u].push_back(v);
		lowie[v].push_back(u);
	}

	auto bfs = [&](int start, const vector<vector<int>>& g) -> vector<int> {
		int sz = (int)g.size();
		vector<int> vis(sz);
		queue<array<int,2>> q;
		q.push({start, 0});
		vis[start] = true;

		vector<int> dist(sz);
		while (!q.empty()) {
			int u = q.front()[0];
			int d = q.front()[1];
			q.pop();

			dist[u] = d;
			for (auto& v: g[u]) if (!vis[v]) {
				vis[v] = true;
				q.push({v, d+1});
			}
		}

		return dist;
	};

	vector<int> db12_1 = bfs(0, gb21);
	int fdb12_1 = max_element(db12_1.begin(), db12_1.end()) - db12_1.begin();

	vector<int> db12_2 = bfs(fdb12_1, gb21);
	int fdb12_actual = max_element(db12_2.begin(), db12_2.end()) - db12_2.begin();

	vector<int> dlowie_1 = bfs(0, lowie);
	int flowie_1 = max_element(dlowie_1.begin(), dlowie_1.end()) - dlowie_1.begin();

	vector<int> dlowie_2 = bfs(flowie_1, lowie);
	int flowie_actual = max_element(dlowie_2.begin(), dlowie_2.end()) - dlowie_2.begin();

	if (ceil(double(dlowie_2[flowie_actual])/2 >= db12_2[fdb12_actual]))
		cout << "FF";
	else cout << "GGEZ";

	return 0;
}
