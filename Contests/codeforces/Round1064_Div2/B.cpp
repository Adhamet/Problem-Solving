#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 a, b, n;
	std::cin >> a >> b >> n;
	std::cout << ((a==b || n*b<=a)? 1: 2) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;	std::cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
