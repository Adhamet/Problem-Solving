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
		int n, m;	std::cin >> n >> m;
		std::string s;	std::cin >> s;

		int x = 0, y = 0, mnX = 0, mxX = 0, mnY = 0, mxY = 0;
		std::pair<int, int> ans = {1,1};
		for (char c: s) {
			if (c == 'L') y--;
			else if (c == 'R') y++;
			else if (c == 'U') x--;
			else if (c == 'D') x++;

			mnY = std::min(mnY, y), mxY = std::max(mxY, y);
			mnX = std::min(mnX, x), mxX = std::max(mxX, x);

			if (mxX - mnX + 1 > n || mxY - mnY + 1 > m) break;
			ans = {1 - mnX, 1 - mnY};
		}

		std::cout << ans.first << ' ' << ans.second << '\n';
	}
	
	return 0;
}
