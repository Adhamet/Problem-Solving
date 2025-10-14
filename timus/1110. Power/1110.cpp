#include <bits/stdc++.h>

using i64 = long long;

int binexp(int base, int exp, int m) {
	int res = 1;
	while (exp) {
		if (exp & 1) res = res * base % m;
		base = base * base % m;
		exp >>= 1;
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m, y;
	std::cin >> n >> m >> y;

	std::vector<int> v;
	for (int x = 1; x < m; ++x) {
		int res = binexp(x, n, m);
		if (res > 1000) break;
		if (res == y) v.push_back(x);
	}
	
	if (v.empty()) std::cout << -1;
	else for (auto &x: v) std::cout << x << ' ';
	return 0;
}
