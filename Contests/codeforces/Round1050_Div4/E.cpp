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
		int n, k;	std::cin >> n >> k;
		std::vector<int> a(n);
		std::map<int,int> cnt;
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
			cnt[a[i]]++;
		}

		bool acc = true;
		std::map<int,int> limit;
		for (auto &c: cnt) {
			if (c.second % k) {
				acc = false;
				break;
			}
			limit[c.first] = c.second / k;
		}

		if (!acc) {
			std::cout << 0 << '\n';
			continue;
		}

		int j = 0;
		i64 ans = 0;
		std::map<int, int> cur;
		for (int i = 0; i < n; ++i) {
			while (j < n && cur[a[j]] < limit[a[j]])
				cur[a[j]]++, j++;
			ans += (j - i);
			cur[a[i]]--;
		}

		std::cout << ans << '\n';
	}
	
	return 0;
}
