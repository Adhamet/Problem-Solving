#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define fs first
#define sc second
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr i64 oo = 1e18;
	int n, m; 
	cin >> n >> m;
	int sky = n;
	vector<vector<i64>> dist(n+1, vector<i64>(n+1, oo));
	for (int i = 0; i <= n; ++i) dist[i][i] = 0;

	for (int i = 0; i < m; ++i) {
		int u, v; i64 w;    
		cin >> u >> v >> w;
		--u; --v;
		dist[u][v] = min(dist[u][v], w);
		dist[v][u] = min(dist[v][u], w);
	}

	int k; i64 t; 
	cin >> k >> t;
	vector<int> d(k);
	for (int i = 0; i < k; ++i) {
		cin >> d[i]; 
		--d[i];
		dist[d[i]][sky] = t;
		dist[sky][d[i]] = 0;
	}

	for (int kk = 0; kk <= n; ++kk) 
		for (int i = 0; i <= n; ++i) if (dist[i][kk] != oo)
			for (int j = 0; j <= n; ++j) if (dist[kk][j] != oo)
				dist[i][j] = min(dist[i][j], dist[i][kk] + dist[kk][j]);

	int q;	cin >> q;
	while (q--) {
		int qry; 
		cin >> qry;
		if (qry == 1) {
			int u, v; i64 w;    
			cin >> u >> v >> w;
			--u; --v;
			for (int i = 0; i <= n; ++i)
				for (int j = 0; j <= n; ++j)
					dist[i][j] = min({ dist[i][j],
							dist[i][u] + w + dist[v][j],
							dist[i][v] + w + dist[u][j] });
		} else if (qry == 2) {
			int v;	cin >> v; 
			--v;
			dist[v][sky] = t;
			dist[sky][v] = 0;

			for (int i = 0; i <= n; ++i) {
				dist[i][sky] = min(dist[i][sky], dist[i][v] + t);
				dist[sky][i] = min(dist[sky][i], dist[v][i]);
			}

			for (int i = 0; i <= n; ++i) 
				for (int j = 0; j <= n; ++j)
					dist[i][j] = min(dist[i][j],
							dist[i][sky] + dist[sky][j]);
		} else {
			i64 sm = 0;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					if (dist[i][j] < oo)
						sm += dist[i][j];
			cout << sm << el;
		}
	}

	return 0;
}

