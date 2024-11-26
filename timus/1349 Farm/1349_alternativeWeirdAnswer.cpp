#include <bits/stdc++.h>
int main() {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	if (n == 0) std::cout << -1;
	else {
		for (int a = 1; a <= 100; ++a) {
			for (int b = a + 1; b <= 100; ++b) {
				for (int c = b + 1; c <= 100; ++c) {
					if (pow(a, n) + pow(b, n) == pow(c, n)) {
						std::cout << a << " " << b << " " << c;
						return 0;
					}
				}
			}
		}
		std::cout << -1;
	}
	return 0;
}
