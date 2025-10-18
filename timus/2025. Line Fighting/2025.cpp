#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;	std::cin >> t;
	while (t--) {
		int n, k;	std::cin >> n >> k;
		if (n % k == 0) {
			int count = k * (k - 1) / 2;
			std::cout << count * (n / k) * (n / k) << '\n';
		} else {
			int x = n - ((n + k - 1) / k) * k;
			x = x / ((n / k) - ((n + k - 1) / k));
			int y = k - x;

			int part1 = (x * (x - 1) / 2) * (n / k) * (n / k);
			int part2 = (y * (y - 1) / 2) * ((n + k - 1) / k) * ((n + k - 1) / k);
			int part3 = (n / k) * ((n + k - 1) / k) * x * y;
			std::cout << part1 + part2 + part3 << '\n';
		}
	}
	
	return 0;
}
