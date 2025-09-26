#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n, q;	std::cin >> n >> q;
	std::vector<int> a(n+1);
	for (int i = 1; i <= n; ++i) std::cin >> a[i];

	std::vector<i64> s0(n + 1), s1(n + 1), s2(n + 1);
	for (int i = 1; i <= n; ++i) {
		s0[i] = s0[i - 1] + a[i];
		s1[i] = s1[i - 1] + i * a[i];
		s2[i] = s2[i - 1] + 1LL * i * i * a[i];
	}

	while (q--) {
		int l, r;	std::cin >> l >> r;
		
		i64 S0 = s0[r] - s0[l - 1];
		i64 S1 = s1[r] - s1[l - 1];
		i64 S2 = s2[r] - s2[l - 1];

		i64 n = (r - l + 1);
		i64 ans = (n + 1) * (S1 - (l - 1) * S0)
			- (S2 - 2 * (l - 1) * S1 + 1LL * (l - 1) * (l - 1) * S0);
		std::cout << ans << '\n';
	}
	
	return 0;
}

