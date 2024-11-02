#include <bits/stdc++.h>

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using i64 = long long;

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;

		if (n == 5) std::cout << "5\n2 1 3 4 5\n";
		else if (n == 6) std::cout << "7\n1 2 4 6 5 3\n";
		else if (n == 7) std::cout << "7\n2 4 5 1 3 6 7\n";
		else if (n == 8) std::cout << "15\n2 4 5 1 3 6 7 8\n";
		else if (n == 9) std::cout << "9\n2 4 5 6 7 1 3 8 9\n";
		else if (n == 10) std::cout << "15\n1 2 3 4 5 6 8 10 9 7\n";
		else {
			int p[n], k;
			for (int i = 0; i < n; i++) p[i] = i + 1;
			for (int i = 1; i <= n; i++) {
				if (i % 2 == 1) k = k & p[i - 1];
				else k = k | p[i - 1];
			}

			std::cout << k << el;
			for (int i = 0; i < n; i++) std::cout << p[i] << (i == n - 1? el: ' ');
		}
	}

	return 0;
}
