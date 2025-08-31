#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;	cin >> n;
	vector<vector<int>> g(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> g[i][j];

	i64 sm = 0;
	for (int i = 0; i < n; ++i)
		sm += accumulate(g[i].begin(), g[i].end(), i64(0));

	i64 mn = g[0][n - 1];
	for (int i = 0; i < n; ++i) 
		mn = min(mn, i64(g[i][n - 1 - i]));

	return cout << sm - mn << '\n', 0;
}
