#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, k, d;
	cin >> n >> k >> d;
	vector<int> police(k);
	for (int i = 0; i < k; ++i) cin >> police[i], police[i]--;

	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0, u, v; i < n-1; ++i) {
		cin >> u >> v;
		u-=1, v-=1;
		adj[u].push_back({v, i+1});
		adj[v].push_back({u, i+1});
	}

	vector<int> dist(n, -1);
	queue<int> q;
	vector<bool> keep(n, false);
	for (const int& p: police) if (dist[p] == -1) {
		dist[p] = 0, q.push(p);
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (const auto& rel: adj[node]) if (dist[rel.first] == -1) {
			dist[rel.first] = dist[node] + 1;
			if (dist[rel.first] > d) continue;
			keep[rel.second] = true;
			q.push(rel.first);
		}
	}

	vector<int> ans;
	for (int i = 1; i <= n - 1; ++i) if (!keep[i]) {
		ans.push_back(i);
	}

	cout << (int)ans.size() << el;
	for (const int& ele: ans) cout << ele << ' ';
	cout << el;
	return 0;
}
