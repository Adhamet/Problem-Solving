#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr i64 oo = (i64)4e18;

	int n, tc = 1;
	while (cin >> n && n) {
		vector<string> name(n);
		struct Edge { int u, v;		i64 w; };
		vector<Edge> edges;
		vector<vector<int>> g(n);

		for (int i = 0; i < n; i++) {
			cin >> name[i];
			for (int j = 0; j < n; j++) {
				i64 w;	cin >> w;
				if (i == j) {
					i64 cost = min(i64(0), w);
					if (cost != 0) {
						edges.push_back({i, i, cost});
						g[i].push_back(i);
					}
				} else if (w != 0) {
					edges.push_back({i, j, w});
					g[i].push_back(j);
				}
			}
		}

		int q; cin >> q;
		vector<pair<int,int>> queries(q);
		for (int i = 0; i < q; i++)
			cin >> queries[i].first >> queries[i].second;

		cout << "Case #" << tc++ << ":" << el;

		vector<i64> dist;
		vector<bool> canReach, neg;
		vector<vector<i64>> dd(n, vector<i64>(n));
		vector<vector<bool>> negcyc(n, vector<bool>(n, false));

		for (int s = 0; s < n; s++) {
			dist.assign(n, oo);
			canReach.assign(n, false);
			neg.assign(n, false);
			dist[s] = 0;
			canReach[s] = true;

			for (int it = 0; it < n-1; it++) {
				bool upd = false;
				for (auto &[u,v,w]: edges) {
					if (dist[u] < oo && dist[u] + w < dist[v]) {
						dist[v] = dist[u] + w;
						canReach[v] = true;
						upd = true;
					}
				}

				if (!upd) break;
			}

			for (auto &[u,v,w]: edges)
				if (dist[u] < oo && dist[u] + w < dist[v])
					neg[v] = true;

			queue<int> q;
			for (int i = 0; i < n; i++) if (neg[i]) q.push(i);
			while (!q.empty()) {
				int u = q.front();	q.pop();
				for (int &v: g[u]) if (!neg[v])
					neg[v] = true, q.push(v);
			}

			for (int t = 0; t < n; t++)
				dd[s][t] = dist[t], negcyc[s][t] = (neg[t]&&canReach[t]);
		}

		for (auto &qr: queries) {
			int u = qr.first, v = qr.second;
			if (negcyc[u][v]) cout << "NEGATIVE CYCLE" << el;
			else if (dd[u][v] == oo)
				cout << name[u] << "-" << name[v] << " NOT REACHABLE" << el;
			else cout << name[u] << "-" << name[v] << " " << dd[u][v] << el;
		}
	}

	return 0;
}

