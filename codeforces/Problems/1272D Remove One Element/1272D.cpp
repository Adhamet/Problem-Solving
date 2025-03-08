#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<vector<int>> dp(n, vector<int>(2, 1));
	for (int i = 1; i < n; ++i) {
		if (i == 1 && a[i - 1] < a[i]) dp[i][0] = dp[i - 1][0] + 1;
		else {
			if (a[i - 1] < a[i]) {
				dp[i][0] = dp[i - 1][0] + 1;
				dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
			}

			if (a[i - 2] < a[i]) dp[i][1] = max(dp[i][1], dp[i - 2][0] + 1);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) ans = max({ans, dp[i][0], dp[i][1]});
	return cout << ans, 0;
}
