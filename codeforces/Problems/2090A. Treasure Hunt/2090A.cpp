#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 x, y, a;
	std::cin >> x >> y >> a;
	a = (a % (x + y));
	if ((a % x) == a) std::cout << "NO\n";
	else std::cout << "YES\n";
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
