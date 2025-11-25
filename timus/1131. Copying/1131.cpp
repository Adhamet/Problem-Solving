#include <bits/stdc++.h>

using i64 = long long;
using ld = long double;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 n, k;	std::cin >> n >> k;
	i64 infected = 1, hrs = 0;
	while (infected < n && infected < k) infected *= 2, hrs++;
	if (infected < n) hrs += ceil((n - infected) / ld(k));
	return std::cout << hrs, 0;
}
