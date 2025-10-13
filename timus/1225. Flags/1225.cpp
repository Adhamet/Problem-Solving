#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;	std::cin >> n;
	if (n == 1) return std::cout << 2 << '\n', 0;
	if (n == 2) return std::cout << 2 << '\n', 0;

	i64 dp[3][3]{}, ndp[3][3]{};
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (i != j && i != 1)
				dp[i][j] = 1;

	for (int len = 2; len < n; ++len) {
		memset(ndp, 0, sizeof(ndp));
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (dp[i][j]) {
					for (int k = 0; k < 3; ++k) {
						if (j == k) continue;
						if (j == 1) {
							if ((i == 0 && k == 2) || (i == 2 && k == 0))
								ndp[j][k] = dp[i][j] + ndp[j][k];
						} else ndp[j][k] = dp[i][j] + ndp[j][k];
					}
				}
			}
		}
		memcpy(dp, ndp, sizeof(dp));
	}

	i64 ans = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (j != 1)
				ans += dp[i][j];
	return std::cout << ans, 0;
}
