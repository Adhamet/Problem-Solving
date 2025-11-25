#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n, a;
	std::cin >> n >> a;

	int cntSm = 0, cntBg = 0;
	for (int i = 0; i < n; ++i) {
		i64 x;	std::cin >> x;
		if (x < a) cntSm++;
		else cntBg++;
	}

	if (cntSm >= cntBg) std::cout << a - 1 << '\n';
	else std::cout << a + 1 << '\n';
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
