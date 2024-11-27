#include <bits/stdc++.h>
int main() {
	std::ios_base::sync_with_stdio(0), std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::unordered_map<int, long long> sumMap, diffMap;
	for (int i = 0; i < n; i++) {
		int x, y;
		std::cin >> x >> y;
		sumMap[x + y] += 1;
		diffMap[x - y] += 1;
	}

	long long ans = 0;
	for (const auto& s: sumMap) ans += (s.second) * (s.second - 1) / 2;
	for (const auto& s: diffMap) ans += (s.second) * (s.second - 1) / 2;
	return std::cout << ans, 0;
}
