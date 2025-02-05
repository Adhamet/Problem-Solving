#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<array<int, 2>>> g(n);
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		u--, v--;
		g[u].push_back({v, w});
	}

	vector<int> cnt(n, 0);
	vector<int> ans;
	priority_queue<array<int, 2>> pq;
	pq.push({0, 0});
	
	while (!pq.empty() && ans.size() < k) {
		int cost = -pq.top()[0], v = pq.top()[1];
		pq.pop();

		if (v == n - 1) ans.push_back(cost);
		if (cnt[v] >= k) continue;
		cnt[v] += 1;

		for (auto &[u, w]: g[v]) pq.push({-(cost + w), u});
	}

	for (auto &x: ans) cout << x << ' ';
	return 0;
}
