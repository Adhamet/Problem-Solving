#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 n, m;
	std::cin >> n >> m;
	i64 ans;
	if (n <= m) ans = 2 * n - 2;
	else ans = 2 * m - 1;
	return std::cout << ans, 0;
}	
