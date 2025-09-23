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
		std::string str;	std::cin >> str;

		if (n == 2) {
			if (str[0] == '0' && str[1] == '0') {
				std::cout << "YES\n" << "2 1\n";
			} else if (str[0] == '1' && str[1] == '1') {
				std::cout << "YES\n" << "1 2\n";
			} else std::cout << "NO\n";
			continue;
		}

		if (std::count(str.begin(), str.end(), '0') == 0) {
			std::cout << "YES\n";
			for (int i = 1; i <= n; ++i) std::cout << i << ' ';
			std::cout << '\n';
			continue;
		}

		int l = -1;
		for (int i = 0; i < n; ++i) if (str[i] == '1') {
			l = i;
			break;
		}

		if (l == -1) {
			std::cout << "YES\n";
			for (int i = 2; i <= n; i += 2) std::cout << i << ' ';
			for (int i = 3; i <= n; i += 2) std::cout << i << ' ';
			std::cout << "1\n";
		} else if (l == 1) {
			std::cout << "NO\n";
		} else {
			bool ok = true;
			int r = l + 1;
			while (r < n) {
				if (str[r] == '1') {
					if (r - l == 2) {
						ok = false;
						break;
					} else l = r;
				}
				r += 1;
			}

			if (ok && (n - l - 1 == 1)) ok = false;

			if (ok) {
				std::cout << "YES\n";
				int idx = 0, last = 1;
				std::vector<int> oIdx;

				for (int i = 0; i < n; ++i) if (str[i] == '1')
					oIdx.push_back(i);

				for (auto idx: oIdx) {
					int val = idx + 1;
					for (int i = val - 1; i >= last; --i)
						std::cout << i << ' ';
					std::cout << val << ' ';
					last = val + 1;
				}

				if (last < n) for (int i = n; i >= last; --i)
					std::cout << i << ' ';
				std::cout << '\n';
			} else std::cout << "NO\n";
		}
	}
	
	return 0;
}
