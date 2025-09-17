#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	constexpr int MOD = 998244353;

	int t;	std::cin >> t;
	while (t--) {
		int n;	std::cin >> n;
		std::vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) std::cin >> a[i];
		for (int i = 0; i < n; ++i) std::cin >> b[i];

		i64 prev[2] = {1, 1};
		for (int i = 1; i < n; ++i) {
			i64 curr[2] = {0, 0};
			for (int j = 0; j < 2; ++j) {
				int prevA = j? b[i-1] : a[i-1];
				int prevB = j? a[i-1] : b[i-1];
				for (int k = 0; k < 2; ++k) {
					int currA = k? b[i]: a[i];
					int currB = k? a[i]: b[i];
					if (prevA <= currA && prevB <= currB)
						curr[k] = (curr[k] + prev[j]) % MOD;
				}
			}
			prev[0] = curr[0];
			prev[1] = curr[1];
		}

		std::cout << (prev[0] + prev[1]) % MOD << '\n';
	}

	return 0;
}

