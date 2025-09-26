#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;	std::cin >> n;
	int ans = 0;
	int negs = 0, zeros = 0;
	for (int i = 0; i < n; ++i) {
		int x;	std::cin >> x;
		if (x == -1) negs += 1;
		else if (x == 0) zeros += 1;
	}

	ans += zeros;
	if (negs % 2) ans += 2;

	std::cout << ans << '\n';
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
