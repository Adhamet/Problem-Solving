#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m, k;	cin >> n >> m >> k;
	vector<vector<int>> g(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> g[i][j];

	vector<vector<int>> pref(n+1, vector<int>(m+1));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			pref[i][j] = g[i-1][j-1] + pref[i-1][j] 
						+ pref[i][j-1] - pref[i-1][j-1];
	
	vector<vector<int>> diff(n+1, vector<int>(m+1, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int ii = i; ii < n; ++ii) {
				for (int jj = j; jj < m; ++jj) {
					int sm = pref[ii+1][jj+1]-pref[i][jj+1]
							-pref[ii+1][j]+pref[i][j];
					if (sm == k) {
						diff[i][j] += 1;
						diff[i][jj+1] -= 1;
						diff[ii+1][j] -= 1;
						diff[ii+1][jj+1] += 1;
					}
				}
			}
		}
	}

	vector<vector<int>> keep(n, vector<int>(m, false));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int v = diff[i][j];
			if (i > 0) v += keep[i-1][j];
			if (j > 0) v += keep[i][j-1];
			if (i > 0 && j > 0) v -= keep[i-1][j-1];
			keep[i][j] = v;
		}
	}
	

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << (keep[i][j]>0? g[i][j]: 0) << ' ';
		cout << el;
	}

	return 0;
}
