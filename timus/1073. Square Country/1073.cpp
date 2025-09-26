#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int sm;	std::cin >> sm;
	std::vector<int> prfsq;
	for (int i = 1; i * i <= sm; ++i) prfsq.push_back(i * i);
	int sz = (int)prfsq.size();

	std::vector<i64> dp(sm + 1, INT_MAX);
	dp[0] = 0;
	for (int s = 0; s <= sm; ++s) {
		for (int c = 0; c < sz; ++c) {
			if (s - prfsq[c] >= 0)
				dp[s] = std::min(dp[s], 1 + dp[s - prfsq[c]]);
		}
	}

	return std::cout << dp[sm], 0;
}
