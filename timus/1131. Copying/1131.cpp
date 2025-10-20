#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 n, k;	std::cin >> n >> k;
	i64 infected = 1, hrs = 0;
	while (infected < n) {
		if (infected < k) infected *= 2;
		else infected += k;
		hrs++;
	}
	return std::cout << hrs, 0;
}
