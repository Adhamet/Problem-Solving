#include <bits/stdc++.h>

using u32 = unsigned int;
using i64 = long long;

void solve() {
	u32 a, b;
	std::cin >> a >> b;
	if (a == b) return void(std::cout << "0\n");
	u32 bitsA = 32 - __builtin_clz(a);
	u32 bitsB = 32 - __builtin_clz(b);
	if (bitsA < bitsB) std::cout << "-1\n";
	else {
		u32 n1;
		n1 = (b & ~a);
		u32 a1 = a ^ n1;
		if (a1 == b) {
			std::cout << "1\n";
			std::cout << n1 << '\n';
		} else {
			u32 n2;
			n2 = (a & ~b);
			u32 a2 = a1 ^ n2;
			std::cout << "2\n";
			std::cout << n1 << ' ' << n2 << '\n';
		}

	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	u32 t;	std::cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
