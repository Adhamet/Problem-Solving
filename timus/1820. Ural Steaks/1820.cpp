#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 n, k;
	std::cin >> n >> k;
	i64 ans = (2 * n + k - 1) / k;
	ans = std::max(2LL, ans);
	std::cout << ans;
	
	return 0;
}
