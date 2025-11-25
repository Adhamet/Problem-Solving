#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int h, b;	std::cin >> h >> b;
	if (h > b) std::cout << h - b;
	else std::cout << 0;
	
	return 0;
}
