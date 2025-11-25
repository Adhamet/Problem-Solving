#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	constexpr int MXW = 500*500 + 2;

	int n;
	std::cin >> n;
	i64 hHappy[n], bHappy[n], partWei[n], sumW = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> partWei[i];
		std::cin >> hHappy[i];
		std::cin >> bHappy[i];
		sumW += partWei[i];
	}

	static i64 dp1[MXW], dp2[MXW];
	i64 *dp = dp1, *ndp = dp2;

	std::fill(dp, dp+MXW, -1);
	dp[0] = 0;

	for (int i = 0; i < n; ++i) {
		std::fill(ndp, ndp+MXW, -1);

		for (int hWei = 0; hWei <= sumW; ++hWei) {
			if (dp[hWei] == -1) continue;

			ndp[hWei] = std::max(ndp[hWei], dp[hWei] + bHappy[i]);
			if (hWei + partWei[i] <= sumW - hWei - partWei[i])
				ndp[hWei + partWei[i]] = std::max(ndp[hWei + partWei[i]], dp[hWei] + hHappy[i]);
		}

		std::swap(dp, ndp);
	}

	i64 ans = 0;
	for (int hWei = 0; hWei <= sumW / 2; ++hWei) ans = std::max(ans, dp[hWei]);

	return std::cout << ans, 0;
}
