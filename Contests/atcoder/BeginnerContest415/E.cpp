#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int h, w;	cin >> h >> w;
	vector<vector<i64>> g(h, vector<i64>(w));
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			cin >> g[i][j];
	vector<i64> p(h + w - 1);
	for (int d = 0; d < h + w - 1; ++d) cin >> p[d];

	auto can = [&](i64 k) -> bool {
		vector<vector<i64>> dp(h, vector<i64>(w, LLONG_MIN));
		dp[0][0] = k + g[0][0] - p[0];
		if (dp[0][0] < 0) return false;

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (dp[i][j] < 0) continue;
				i64 cur = dp[i][j];
				if (i + 1 < h) {
					i64 nm = cur + g[i+1][j] - p[i+1 + j];
					dp[i+1][j] = max(dp[i+1][j], nm);
				}
				if (j + 1 < w) {
					i64 nm = cur + g[i][j+1] - p[i + j+1];
					dp[i][j+1] = max(dp[i][j+1], nm);
				}
			}
		}

		return dp[h-1][w-1] >= 0;
	};

	i64 l = 0, r = 2e15, ans = -1;
	while (l <= r) {
		i64 mid = (l + r) >> 1;
		if (can(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	return cout << ans, 0;
}
