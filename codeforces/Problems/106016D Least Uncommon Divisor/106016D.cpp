#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	i64 n, x;
	std::cin >> n >> x;

	i64 xx = x;
	std::vector<std::pair<i64,int>> primeFactors;
	for (i64 p = 2; p * p <= xx; ++p) if (xx % p == 0) {
		int cnt = 0;
		while (xx % p == 0) xx /= p, cnt++;
		primeFactors.push_back({p, cnt});
	}
	if (xx > 1) primeFactors.push_back({xx, 1});

	for (int i = 0; i < n; ++i) {
		i64 y;	std::cin >> y;
		i64 g = std::gcd(x, y);
		
		i64 gg = g;
		i64 mn = -1;
		i128 mnval = (__int128)LLONG_MAX;

		for (auto [p, xexp]: primeFactors) {
			int yexp = 0;
			while (gg % p == 0) gg /= p, yexp++;

			if (yexp < xexp) {
				i128 curval = 1;
				for (int j = 0; j < yexp + 1; ++j) curval *= p;
				if (curval < mnval) mnval = curval, mn = (i64)mnval;
			}
		}

		std::cout << mn << '\n';
	}
	
	return 0;
}
