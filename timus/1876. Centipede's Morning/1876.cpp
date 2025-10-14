#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
		
	int a, b;	std::cin >> a >> b;
	std::cout << std::max(40 + 2 * b, 2 * a + 39);
	
	return 0;
}
