#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int oo = 1e18;
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<int> dp(n, oo);
	dp[0] = 0, dp[1] = abs(a[0] - a[1]);
	for (int i = 2; i < n; ++i) {
		for (int j = max(0LL, i - k); j < i; ++j) {
			dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
		}
	}

	return cout << dp[n - 1], 0;
}

