#include <bits/stdc++.h>

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using i64 = long long;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;

		if (n == 1 || n == 3) std::cout << -1 << el;
		else if (n % 2 == 0) std::cout << std::string(n - 2, '3') + "66" << el;
		else std::cout << std::string(n - 5, '3') + "36366" << el;
	}

	return 0;
}
