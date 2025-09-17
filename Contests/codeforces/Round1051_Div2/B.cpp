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
		int n, k;
		std::cin >> n >> k;

		std::vector<i64> prod(n);
		for (int i = 0; i < n; ++i) std::cin >> prod[i];
		std::sort(prod.begin(), prod.end());
		std::vector<int> vouch(k);
		for (int i = 0; i < k; ++i) std::cin >> vouch[i];
		std::sort(vouch.rbegin(), vouch.rend());
		
		i64 ans = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (!vouch.empty()) {
				int cur = vouch.back();
				vouch.pop_back();
	
				/*std::cout << "\nVOUCH: " << cur << "\n";*/
				int sz = i - cur + 1;
				/*std::cout << "SZ: " << sz << "\n";*/
				if (sz >= 0) {
					for (int j = i; j >= sz; --j) {
						/*std::cout << "TEST2: " << prod[j] << "\n";*/
						if (j != sz) ans += prod[j];
					}

					i = sz;
				} else ans += prod[i];
			} else ans += prod[i];
		}

		std::cout << ans << '\n';
	}
	
	return 0;
}
