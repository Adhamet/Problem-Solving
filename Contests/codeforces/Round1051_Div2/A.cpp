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
		int idx;
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
			if (a[i] == n) idx = i;
		}

		bool ok = true;
		int l = idx - 1, r = idx + 1;
		int nxt = n - 1;
		while (l >= 0 || r < n) {
			if (a[l] == nxt) {
				l--;
				nxt--;
			} else if (a[r] == nxt) {
				r++;
				nxt--;
			} else {
				ok = false;
				break;
			}
		}

		std::cout << (ok? "YES": "NO") << '\n';
	}
	
	return 0;
}
