#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	while (cin >> n) {
		if (n == 0) break;
		cin >> m;
		vector<vector<double>> d(n, vector<double>(n, 0.0));
		for (int i = 0; i < n; ++i) d[i][i] = 1.0;

		for (int i = 0; i < m; i++) {
			int u, v, w;	cin >> u >> v >> w;
			--u, --v;
			double prob = w / 100.0;
			d[u][v] = prob, d[v][u] = prob;
		}

		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					d[i][j] = max(d[i][j], d[i][k] * d[k][j]);
		cout << fixed << setprecision(6) << (d[0][n - 1] * 100.0) << " percent" << el;
	} return 0;
}
