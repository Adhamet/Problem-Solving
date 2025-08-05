#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define int i64
#define pii pair<int,int>
#define fs first
#define sc second
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;	cin >> n;
	vector<array<int, 3>> p(n);
	for (int i = 0; i < n; ++i) cin >> p[i][0] >> p[i][1] >> p[i][2];

	int m = 0;
	for (int i = 0; i < n; ++i) m = max(m, p[i][0] + p[i][1]);

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	iota(dp[n].begin(), dp[n].end(), 0);

	for (int i = n - 1; i >= 0; --i) {
		auto [pi, a, b] = p[i];
		for (int j = 0; j <= m; ++j) {
			if (j <= pi) dp[i][j] = dp[i + 1][j + a];
			else dp[i][j] = dp[i + 1][j - min(j, b)];
		}
	}

	vector<int> smB(n);
	for (int i = 0; i < n; ++i) smB[i] = p[i][2];
	partial_sum(smB.begin(), smB.end(), smB.begin());

	auto access = [&](int x) {
		if (x <= m) return dp[0][x];
		auto it = lower_bound(smB.begin(), smB.end(), x - m);
		if (it == smB.end()) return x - smB.back();
		int idx = it - smB.begin();
		return dp[idx + 1][x - min(x, *it)];
	};

	int q;	cin >> q;
	while (q--) {
		int x;	cin >> x;
		cout << access(x) << el;
	}

	return 0;
}
