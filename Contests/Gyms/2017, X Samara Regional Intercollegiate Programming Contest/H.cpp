#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	int mxVal = 0, imx = -1, jmx = -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] > mxVal) {
				mxVal = a[i][j];
				imx = i;
				jmx = j;
			}
		}

	int mx1 = 0, j1 = -1;
	for (int i = 0; i < n; ++i) {
		if (i == imx) continue;
		for (int j = 0; j < m; ++j) {
			if (a[i][j] > mx1) {
				mx1 = a[i][j];
				j1 = j;
			}
		}
	}

	int rem1 = 0;
	for (int i = 0; i < n; ++i) {
		if (i == imx) continue;
		for (int j = 0; j < m; ++j) {
			if (j == j1) continue;
			rem1 = max(rem1, a[i][j]);
		}
	}

	int mx2 = 0, i2 = -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (j == jmx) continue;
			if (a[i][j] > mx2) {
				mx2 = a[i][j];
				i2 = i;
			}
		}

	int rem2 = 0;
	for (int i = 0; i < n; ++i) {
		if (i == i2) continue;
		for (int j = 0; j < m; ++j) {
			if (j == jmx) continue;
			rem2 = max(rem2, a[i][j]);
		}
	}

	if (rem1 <= rem2) cout << imx + 1 << ' ' << j1 + 1 << el;
	else cout << i2 + 1 << ' ' << jmx + 1 << el;
	return 0;
}

