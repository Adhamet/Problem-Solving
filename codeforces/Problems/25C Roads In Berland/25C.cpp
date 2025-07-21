#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define int i64
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int oo = 1e9;

	int n;	cin >> n;
	vector<vector<int>> d(n, vector<int>(n, oo));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> d[i][j];

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int sm = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			sm += d[i][j];

	int kk;	cin >> kk;
	for (int k = 0; k < kk; ++k) {
		int u, v, w;	cin >> u >> v >> w;
		--u, --v;
		if (w < d[u][v]) {
			sm -= (d[u][v] - w);
			d[u][v] = d[v][u] = w;
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					int nmn = min(
						d[i][u] + w + d[v][j],
						d[i][v] + w + d[u][j]
					);
	
					if (nmn < d[i][j]) {
						sm -= (d[i][j] - nmn);
						d[i][j] = d[j][i] = nmn;
					}
				}
			}
		}

		cout << sm << ' ';
	}

	return 0;
}
