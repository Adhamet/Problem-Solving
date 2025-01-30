#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, r, m;
		cin >> n >> r >> m;
		vector<vector<int>> adj(n + 1);
		for (int i = 0, u, v; i < r; ++i) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<array<int, 2>> soldiers(m);
		for (int i = 0; i < m; ++i) cin >> soldiers[i][0] >> soldiers[i][1];

		int cnt = 0;
		for (auto& soldier: soldiers) {
			int u = soldier[0], v = soldier[1];
			
			vector<bool> vis(adj.size(), false);
			queue<array<int, 2>> q;
			q.push({u, 0});
			vis[u] = true;
			cnt += 1;
			
			while (!q.empty()) {
				int node = q.front()[0];
				int dist = q.front()[1];
				q.pop();

				if (dist >= v) continue;
				for (auto child: adj[node]) if (!vis[child]) {
					vis[child] = true;
					cnt += 1;
					q.push({child, dist + 1});
				}
			}
		}

		cout << (cnt == n? "Yes": "No") << el;
	}
	
	return 0;
}
