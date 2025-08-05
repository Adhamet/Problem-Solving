#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, x, y;	cin >> n >> x >> y;
		--x, --y;
		vector<vector<int>> g(n);
		for (int i = 0, u, v; i < n - 1; ++i) {
			cin >> u >> v;	--u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		queue<array<int,2>> q;
		vector<int> timer(n, 1e9);
		q.push({x,0});
		q.push({y,0});
		timer[x] = 0, timer[y] = 0;

		while (!q.empty()) {
			auto [u, t] = q.front();
			q.pop();

			int ct = t + 1;
			for (auto &v: g[u]) if (timer[v] == 1e9) {
				q.push({v, ct});
				timer[v] = min(timer[v], ct++);
			}
		}

		cout << *max_element(timer.begin(), timer.end()) - 1 << el;
	}

	return 0;
}
