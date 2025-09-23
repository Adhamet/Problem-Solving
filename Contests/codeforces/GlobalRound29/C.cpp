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
		std::string str;
		std::cin >> str;

		bool ok = true;
		int i = 0;
		while (i < n) {
			int j = i;
			while (j + 1 < n && !(str[j] == '1' && str[j+1] == '1')) ++j;

			bool has00 = false;
			for (int k = i; k + 1 <= j; ++k) if (str[k] == '0' && str[k+1] == '0') { 
				has00 = true;
				break;
			}

			if (!has00 && str[i] == '1' && str[j] == '1') {
				int zeros = 0;
				for (int k = i; k <= j; ++k) if (str[k] == '0') ++zeros;
				if (zeros % 2 == 1) { ok = false; break; }
			}

			i = j + 1;
		}

		if (ok) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	
	return 0;
}

