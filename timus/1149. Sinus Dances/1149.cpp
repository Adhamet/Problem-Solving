#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
		
	int n;	std::cin >> n;
	for (int i = 1; i < n; ++i) std::cout << '(';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (j > 1) std::cout << (j&1? '+': '-');
			std::cout << "sin(" << j;
		}
		for (int j = 1; j <= i; ++j) std::cout << ")";
		std::cout << '+' << n-i+1;
		if (i != n) std::cout << ")";
	}
	
	return 0;
}
