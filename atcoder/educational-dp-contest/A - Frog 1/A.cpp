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

	vector<int> dp(n, 0);
	dp[0] = 0, dp[1] = abs(a[0] - a[1]);
	for (int i = 2; i < n; ++i) {
		dp[i] = dp[i - 1] + abs(a[i] - a[i - 1]);
		dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
	}

	return cout << dp[n - 1], 0;
}
