#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 n, ans = 0;	std::cin >> n;
	for (int i = 1; i <= n; ++i) ans += (i * (i + 1) / 2) + (i * (i + 1));
	return std::cout << ans, 0;
}
