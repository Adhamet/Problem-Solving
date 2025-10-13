#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;	std::cin >> t;
	while (t--) {
		i64 k;	std::cin >> k;
		i64 val = 8 * k - 7;
		i64 usq = sqrtl(val);
		if (usq * usq == val) std::cout << 1 << ' ';
		else std::cout << 0 << ' ';
	}

	return 0;
}
