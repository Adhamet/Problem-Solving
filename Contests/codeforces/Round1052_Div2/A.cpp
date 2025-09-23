#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int t;	std::cin >> t;
	while (t--) {
		int n;	std::cin >> n;
		std::vector<int> a(n);
		std::map<int,int> f;
		for (int i = 0; i < n; ++i) std::cin >> a[i], f[a[i]]++;

		int ans = 0;
		for (int k = 1; k <= n; ++k) {
			int cur = 0;
			for (auto &ff: f) if (ff.second >= k)
				++cur;
			ans = std::max(ans, k*cur);
		}

		std::cout << ans << '\n';
	}
	
	return 0;
}
