#include <bits/stdc++.h>
#include <iomanip>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout << std::fixed << std::setprecision(10);
	
	int n;
	double p;
	std::cin >> n >> p;

	double res = 1.0;
	while (n) {
		if (n & 1) {
			res = res * (1 - p) + (1 - res) * p;
		}
		p = p * (1 - p) + (1 - p) * p;
		n = (n >> 1);
	}
	
	return std::cout << res, 0;
}
