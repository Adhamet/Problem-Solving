#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr i64 oo = 1e18;

	int testcases;	cin >> testcases;
	for (int tc = 1; tc <= testcases; ++tc) {
		int n, m;	cin >> n >> m;
		int s = n;
		vector<vector<array<i64,2>>> g(n + 1);
		for (int i = 0, u, v; i < m; ++i) {
			i64 w;	cin >> u >> v >> w;
			--u, --v;
			g[u].push_back({v, w});
		} 

		for (int i = 0; i < n; ++i) g[s].push_back({i, 0});

		bool deny = false;
		vector<int> cnt(n + 1, 0);
		vector<i64> d(n + 1, oo);
		vector<bool> inqueue(n + 1, false);
		queue<int> q;
		q.push(s);	inqueue[s] = true;  d[s] = 0;

		while (!q.empty()) {
			int v = q.front();
			q.pop();	inqueue[v] = false;

			for (auto &[vv, w]: g[v]) if (d[v] + w < d[vv]) {
				d[vv] = d[v] + w;
				if (!inqueue[vv]) {
					q.push(vv);	inqueue[vv] = true;
					cnt[vv]++;
					if (cnt[vv] > n) {
						deny = true;
						break;
					}
				}
			}

			if (deny) break;
		}

		if (deny) cout << "graph " << tc << " no" << el << el;
		else {
			cout << "graph " << tc << " yes" << el << el;
			for (int i = 0; i < n; ++i) cout << d[i] << ' ';
			cout << d[n] << el << el;

			for (int i = 0; i < n; ++i) {
				vector<i64> rd(n, oo);
				priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;
				rd[i] = 0;
				pq.push({0, i});

				while (!pq.empty()) {
					auto [w, u] = pq.top(); pq.pop();
					
					if (w > rd[u]) continue;
					for (auto &[vv, w]: g[u]) {
						i64 nw = w + d[u] - d[vv];
						if (rd[u] + nw < rd[vv]) {
							rd[vv] = rd[u] + nw;
							pq.push({rd[vv], vv});
						}
					}
				}

				for (int j = 0; j < n; ++j) {
					if (rd[j] == oo) cout << "#";
					else cout << (rd[j] + d[j] - d[i]);
					cout << (j < n - 1? ' ': el);
				}
			}

			cout << el;
		}
	}

	return 0;
}

