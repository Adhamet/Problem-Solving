#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t, tc = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> coins(n);
		for (int i = 0; i < n; ++i) cin >> coins[i];

		if (n == 0) {
			cout << "Case " << tc++ << ": 0" << el;
			continue;
		}

		if (n == 1) {
			cout << "Case " << tc++ << ": " << coins[0] << el;
			continue;
		}

		vector<int> dp(n);
		dp[0] = coins[0];
		dp[1] = max(coins[0], coins[1]);
		for (int i = 2; i < n; ++i) dp[i] = max(dp[i - 1], dp[i - 2] + coins[i]);
		cout << "Case " << tc++ << ": " << dp[n - 1] << el;
	}

	return 0;
}

