#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 t1, t2;		std::cin >> t1 >> t2;
	i64 cnt = 0;
	for (int i = 0; i < 10; ++i) {
		i64 x;	std::cin >> x;
		cnt += x;
	}
	if (t1 + (cnt * 20) <= t2) std::cout << "No chance.";
	else std::cout << "Dirty debug :(";

	return 0;
}
