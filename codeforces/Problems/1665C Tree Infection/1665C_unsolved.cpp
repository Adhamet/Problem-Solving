#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<vector<int>> g(n);
		g[0].push_back(0);
		for (int u = 2, v; u <= n; ++u) {
			cin >> v;
			g[u - 1].push_back(v - 1);
			g[v - 1].push_back(u - 1);
		}

		vector<int> grpSz;
		grpSz.push_back(1);	// for 1
		auto dfs = [&](auto &self, int u, int p) -> void {
			int cntCh = 0;
			for (auto &v: g[u]) if (v != p) cntCh++;
			if (cntCh > 0) grpSz.push_back(cntCh);
			for (auto &v: g[u]) if (v != p) self(self, v, u);
		};
		dfs(dfs, 0, 0);

		sort(grpSz.rbegin(), grpSz.rend());

		int m = (int)grpSz.size(), time = m;
		vector<int> startTime(m);
		for (int i = 0; i < m; ++i) startTime[i] = i + 1;
		for (int i = 0; i < m; ++i) {
			/*cerr << "i: " << grpSz[i] << ' ' << time << ' ' << startTime[i] << '\n';*/
			int left = grpSz[i] - (1 + (time - startTime[i]));
			if (left > 0) time += (left + 1) / 2;
		}

		cout << time << '\n';
	}

	return 0;
}
