#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 x, y, c;	std::cin >> x >> y >> c;
	if (x + y >= c) {
		if (x >= y) std::cout << std::min(x, c) << ' ' << c - std::min(x, c);
		else std::cout << c - std::min(y, c) << ' ' << std::min(y, c);
	} else std::cout << "Impossible";
	
	return 0;
}
