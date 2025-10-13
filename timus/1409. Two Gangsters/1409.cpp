#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int a, b;
	std::cin >> a >> b;
	int tot = a + b - 1;
	std::cout << tot - a << ' ' << tot - b;
	
	return 0;
}
