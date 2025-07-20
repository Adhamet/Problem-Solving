#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		int n;	cin >> n;
		vector<vector<i64>> d(n, vector<i64>(n));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> d[i][j];

		for (int k = 0; k < n; ++k) 
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j) if (i != j)
					d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
		i64 sm = 0;
		int r;	cin >> r;
		while (r--) {
			int u, v;	cin >> u >> v;
			sm += d[--u][--v];
		}

		cout << "Case #" << tc << ": " << sm << el;
	}

	return 0;
}
