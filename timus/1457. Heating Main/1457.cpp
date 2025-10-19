#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout << std::fixed << std::setprecision(6);
	int n, sm = 0;	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;	std::cin >> x;
		sm += x;
	}
	return std::cout << (sm / (n * 1.0)), 0;
}
