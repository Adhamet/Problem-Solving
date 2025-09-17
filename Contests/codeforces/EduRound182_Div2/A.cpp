#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int t;	std::cin >> t;
	while (t--) {
		int n;	std::cin >> n;
		std::vector<int> a(n);
		for (int i =0 ; i < n; ++i) std::cin >> a[i];

		bool acc = false;
		for (int l = 1; l < n - 1; ++l) {
			for (int r = l + 1; r < n; ++r) {
				int s1 = 0;
				for (int i = 0; i < l; ++i) s1 += a[i];
				int s2 = 0;
				for (int i = l; i < r; ++i) s2 += a[i];
				int s3 = 0;
				for (int i = r; i < n; ++i) s3 += a[i];

				s1 %= 3, s2 %= 3, s3 %= 3;
				if (s1 == s2 && s1 == s3) {
					std::cout << l << ' ' << r << '\n';
					acc = true;
					break;
				}
				if (s1 != s2 && s2 != s3 && s1 != s3) {
					std::cout << l << ' ' << r << '\n';
					acc = true;
					break;
				}
			}
			if (acc) break;
		}
		if (!acc) std::cout << "0 0\n";
	}
	
	return 0;
}
