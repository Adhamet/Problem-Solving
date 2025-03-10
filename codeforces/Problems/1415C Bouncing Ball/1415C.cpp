#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int tt;
	cin >> tt;
	
	while (tt--) {
		string s;
		int n, p, k, x, y;
		cin >> n >> p >> k >> s >> x >> y;

		vector<int> dp(n + 1);
		for (int i = n - 1; i >= 0; --i) {
			dp[i + 1] = (s[i] == '0');
			if (i + k < n) dp[i + 1] += dp[i + k + 1];
		}

		int ans = LLONG_MAX;
		for (int i = p; i <= n; ++i) ans = min(ans, dp[i] * x + (i - p) * y);
		cout << ans << el;
	}

	return 0;
}
