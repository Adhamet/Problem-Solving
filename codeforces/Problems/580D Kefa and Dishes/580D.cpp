#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m, k;	cin >> n >> m >> k;
	vector<i64> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<vector<i64>> g(n, vector<i64>(n, 0));
	for (int i = 0, u, v, w; i < k; ++i) {
		cin >> u >> v >> w;
		--u,--v;
		g[u][v] = w;
	}

	i64 dp[(1<<n)][n];
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < n; ++i) dp[1 << i][i] = a[i];

	for (int msk = 1; msk < (1 << n); ++msk) {
		for (int lst = 0; lst < n; ++lst) if (msk & (1 << lst)) {
			for (int curr = 0; curr < n; ++curr) if (!(msk & (1 << curr))) {
				int nmsk = msk | (1 << curr);
				dp[nmsk][curr] = max(dp[nmsk][curr],
							dp[msk][lst]+a[curr]+g[lst][curr]);
			}
		}
	}

	i64 ans = 0;
	for (int msk = 1; msk < (1<<n); ++msk) {
		if (__builtin_popcount(msk) != m) continue;
		for (int lst = 0; lst < n; ++lst) ans = max(ans, dp[msk][lst]);
	}

	return cout << ans, 0;
}
