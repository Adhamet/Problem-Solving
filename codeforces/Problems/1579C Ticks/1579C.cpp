#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, m, k;	cin >> n >> m >> k;
		vector<vector<char>> g(n, vector<char>(m));

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> g[i][j];

		auto check = [&](int i, int j, int d) -> bool { 
			if (i < 0 || i >= n || j < 0 || j >= m || j+d < 0 || j+d >= m) return false;
			return g[i][j] == '*' && g[i][j+d] == '*';
		};

		bool acc = true;
		vector<vector<int>> mark(n, vector<int>(m));
		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < m; ++j) {
				if (g[i][j] == '*') {
					int ii = i, jj = j, tickLen = 0;

					ii--, jj--;
					int d = 2;
					while (check(ii, jj, d)) {
						tickLen += 1;
						ii--, jj--;
						d += 2;
					}

					if (tickLen >= k) {
						ii = i, jj = j;
						mark[ii][jj] = 1;
						ii--, jj--;
						d = 2;
						while (check(ii, jj, d)) {
							mark[ii][jj] = mark[ii][jj+d] = 1;
							ii--, jj--;
							d += 2;
						}
					}
				}
			}
		}

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (g[i][j] == '*' && !mark[i][j])
					acc = false;

		cout << (acc? "YES": "NO") << '\n';
	}

	return 0;
}
