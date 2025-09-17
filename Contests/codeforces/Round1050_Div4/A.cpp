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
		int x, n;	std::cin >> x >> n;
		int lst = x + n, ans = 0;
		bool turn = false;
		for (int i = 0; i < n; ++i) {
			if (!turn) ans += x;
			else ans -= x;
			turn = !turn;
		}
		std::cout << ans << '\n';
	}
	
	return 0;
}

