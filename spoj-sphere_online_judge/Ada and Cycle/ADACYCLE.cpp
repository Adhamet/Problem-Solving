#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x;
			cin >> x;
			if (x) adj[i].push_back(j);
		}
	}

	vector<bool> vis(n);
	vector<int> dist(n, -1);
	for (int i = 0; i < n; ++i) {
		if (adj[i].size() == 0) cout << "NO WAY" << el;
		else {
			for (int i = 0; i < n; ++i) vis[i] = false;
			queue<int> q;
			q.push(i);
			dist[i] = 0;
			vis[i] = true;

			int ans = -1;
			bool found = false;
			while (!q.empty()) {
				int node = q.front();
				q.pop();

				vis[node] = true;
				for (const auto& child: adj[node]) {
					if (child == i) {
						ans = dist[node] + 1;
						break;
					}

					if (!vis[child]) {
						vis[child] = true;
						dist[child] = dist[node] + 1;
						q.push(child);
					}
				}

				if (ans != -1) break;
			}

			if (ans == -1) cout << "NO WAY" << el;
			else cout << ans << el;
		}
	}
	return 0;
}
