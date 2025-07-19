#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define int i64
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int oo = 4e18;

	int n, m, q;	cin >> n >> m >> q;
	vector<vector<int>> d(n, vector<int>(n, oo));
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		--u, --v;
		d[u][v] = min(d[u][v], w);
		d[v][u] = min(d[v][u], w);
	}

	vector<vector<int>> dist(n, vector<int>(n));
	for (int i = 0; i < n; ++i) d[i][i] = 0;

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	while (q--) {
		int u, v;	cin >> u >> v;
		cout << (d[--u][--v] == oo? -1: d[u][v]) << el;
	}

	return 0;
}
