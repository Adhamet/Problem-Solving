#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::map<int, bool> mp;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		mp[a[i]] = 1;
	}

	int m;
	std::cin >> m;
	bool ok = false;
	for (int j = 0; j < m; ++j) {
		int x;	std::cin >> x;
		if (mp[10000 - x]) {
			ok = true;
		}
	}

	return std::cout << (ok? "YES": "NO"), 0;
}
