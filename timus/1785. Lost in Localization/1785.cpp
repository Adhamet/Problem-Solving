#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	if (n >= 1 && n <= 4) std::cout << "few";
	else if (n >= 5 && n <= 9) std::cout << "several";
	else if (n >= 10 && n <= 19) std::cout << "pack";
	else if (n >= 20 && n <= 49) std::cout << "lots";
	else if (n >= 50 && n <= 99) std::cout << "horde";
	else if (n >= 100 && n <= 249) std::cout << "throng";
	else if (n >= 250 && n <= 499) std::cout << "swarm";
	else if (n >= 500 && n <= 999) std::cout << "zounds";
	else if (n >= 1000) std::cout << "legion";
	
	return 0;
}
