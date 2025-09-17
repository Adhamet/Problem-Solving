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
		for (int i = 0; i < n; ++i) std::cin >> a[i];
		std::string s;	std::cin >> s;

		std::vector<std::pair<int, char>> v;
		for (int i = 0; i < n; ++i) v.push_back({a[i], s[i]});
		std::sort(v.begin(), v.end());

		bool ok = true;
		int cur = 1;
		for (auto [val, col]: v) {
			if (col == 'B') {
				if (val < cur) {
					ok = false;
					break;
				}
				++cur;
			}
		}
		for (auto [val, col]: v) {
			if (col == 'R') {
				if (val > cur) {
					ok = false;
					break;
				}
				++cur;
			}
		}

		std::cout << (ok? "YES": "NO") << '\n';
	}
	
	return 0;
}
