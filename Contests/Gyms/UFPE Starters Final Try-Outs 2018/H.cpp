#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'
#define int i64

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, c, m;	cin >> n >> c >> m;
	vector<bool> hasCBH(n, false);
	for (int i = 0, u; i < c; ++i) {
		cin >> u;
		hasCBH[u - 1] = true;
	}

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
	}

	auto bfs = [&](bool maximize) {
		vector<int> dist(n, maximize ? INT_MIN: INT_MAX);
		deque<int> dq;

		dist[0] = hasCBH[0];
		dq.push_front(0);
		while (!dq.empty()) {
			int v = dq.front(); dq.pop_front();

			for (int &vv : g[v]) {
				int nd = dist[v] + hasCBH[vv];
				if (!maximize && nd < dist[vv]) {
					dist[vv] = nd;
					if (hasCBH[vv] == 0) dq.push_front(vv);
					else dq.push_back(vv);
				} else if (maximize && nd > dist[vv]) {
					dist[vv] = nd;
					if (hasCBH[vv] == 1) dq.push_front(vv);
					else dq.push_back(vv);
				}
			}
		}

		return dist[n - 1];
	};

	int minCBH = bfs(false);
	int maxCBH = bfs(true);
	return cout << minCBH << ' ' << maxCBH, 0;
}

