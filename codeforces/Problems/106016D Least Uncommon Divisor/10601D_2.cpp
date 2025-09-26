#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	i64 n, x;	std::cin >> n >> x;

	std::vector<int> divs;
	for (int i = 1; i * i <= x; ++i) if (x % i == 0) {
		divs.push_back(i);
		if (i * i != x) divs.push_back(x / i);
	}
	std::sort(divs.begin(), divs.end());

	int szD = (int)divs.size();
	std::vector<int> lcmPref(szD);
	lcmPref[0] = divs[0];
	for (int i = 1; i < szD; ++i) lcmPref[i] = std::lcm(lcmPref[i - 1], divs[i]);

	for (int i = 0; i < n; ++i) {
		i64 y;	std::cin >> y;
		i64 g = std::gcd(x, y);

		int l = 0, r = szD - 1, ans = -1;
		while (l <= r) {
			int md = (l + r) >> 1;
			if (g % lcmPref[md] != 0) r = md - 1, ans = md;
			else l = md + 1;
		}

		std::cout << (ans == -1? -1: divs[ans]) << '\n';
	}

	
	return 0;
}
