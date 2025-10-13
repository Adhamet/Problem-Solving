#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;	std::cin >> n >> m;
	std::vector<int> cnt(n + 1);
	for (int i = 0; i < m; ++i) {
		int x;	std::cin >> x;
		++cnt[x];
	}
	
	std::cout << std::fixed << std::setprecision(2);
	for (int i = 1; i <= n; ++i) std::cout << (cnt[i] * 100.0 / m) << "%\n";
	return 0;
}
