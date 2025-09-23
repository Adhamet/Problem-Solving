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
		int x, y;	std::cin >> x >> y;

		if (x < y) std::cout << 2 << '\n';
		else {
			if (y > 1 && y < x - 1) std::cout << 3 << '\n';
			else std::cout << -1 << '\n';
		}
	}
	
	return 0;
}
