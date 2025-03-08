#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> b(n + 1, vector<int>(m + 1, 0));
	vector<vector<char>> a(n + 1, vector<char>(m + 1, '0'));

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j], b[i][j] = (a[i][j] - '0');

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			b[i][j] += b[i - 1][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			b[i][j] += b[i][j - 1];

	int ans = 0;
	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= m; y1++) {
			for (int x2 = x1; x2 <= n; x2++) {
				for (int y2 = y1; y2 <= m; y2++) {
					int currans = b[x2][y2] - b[x2][y1 - 1] - b[x1 - 1][y2] + b[x1 - 1][y1 - 1];
					if (currans == 0) ans = max(ans, 2 * (x2 - x1 + 1) + 2 * (y2 - y1 + 1));
				}
			}
		}
	}

	return cout << ans, 0;
}

