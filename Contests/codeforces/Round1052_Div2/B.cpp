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
		int n, m;	std::cin >> n >> m;
		std::vector<std::vector<int>> vs(n);
		std::vector<int> freq(m + 1, 0);
		for (int i = 0; i < n; ++i) {
			int len;	std::cin >> len;
			vs[i].resize(len);
			for (int j = 0; j < len; ++j) {
				std::cin >> vs[i][j];
				freq[vs[i][j]]++;
			}
		}

		bool ok = true;
		for (int i = 1; i <= m; ++i) ok &= (freq[i] >= 1);
		if (!ok) {
			std::cout << "NO\n";
			continue;
		}

		int cnt = 1;
		for (int i = 0; i < n; ++i) {
			ok = true;
			for (auto x: vs[i]) ok &= (--freq[x] > 0);
			if (ok) cnt++;
			for (auto x: vs[i]) freq[x]++;
		}

		std::cout << (cnt >= 3? "YES": "NO") << '\n';
	}
	
	return 0;
}
