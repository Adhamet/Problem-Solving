#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;	std::cin >> n;
	int smP = n * (n + 1) / 2;

	std::cout << 2 << ' ' << 1 << ' ' << n << '\n';
	std::cout.flush();
	i64 smA;	std::cin >> smA;

	i64 totInc = smA - smP;
	int l = 1, r = n;
	while (l < r) {
		int md = (l + r) >> 1;
		std::cout << 1 << ' ' << 1 << ' ' << md << '\n';
		std::cout.flush();
		i64 curP;	std::cin >> curP;
		std::cout << 2 << ' ' << 1 << ' ' << md << '\n';
		std::cout.flush();
		i64 curA;	std::cin >> curA;
		if (curA - curP <= 0) l = md + 1;
		else r = md;
	}

	std::cout << '!' << ' ' << l << ' ' << l+(int)totInc-1 << '\n';
	std::cout.flush();
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
