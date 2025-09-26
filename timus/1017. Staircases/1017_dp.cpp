#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n;	std::cin >> n;
	using vi64 = std::vector<i64>;
	std::vector<vi64> dp(n+1, vi64(n+1, 0));

	for (int m = 0; m <= n; ++m) dp[0][m] = 1;

	for (int s = 1; s <= n; ++s) {
		for (int m = 1; m <= n; ++m) {
			dp[s][m] = dp[s][m - 1];
			if (s >= m) dp[s][m] += dp[s - m][m - 1];
		}
	}

	return std::cout << dp[n][n] - 1 << '\n', 0;
}
