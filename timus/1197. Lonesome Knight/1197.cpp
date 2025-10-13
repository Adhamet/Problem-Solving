#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	auto getCol = [](char ch) {
		if (ch == 'a') return 1;
		if (ch == 'b') return 2;
		if (ch == 'c') return 3;
		if (ch == 'd') return 4;
		if (ch == 'e') return 5;
		if (ch == 'f') return 6;
		if (ch == 'g') return 7;
		return 8;
	};
	auto inside = [](int r, int c) { return r >= 1 && r <= 8 && c >= 1 && c <= 8; };
	const int dr[] = {2, -2, 2, -2, 1, -1, 1, -1};
	const int dc[] = {1, 1, -1, -1, 2, 2, -2, -2};

	int t;	std::cin >> t;
	while (t--) {
		std::string s;	std::cin >> s;
		int row = 8 - (s[1] - '0') + 1;
		int col = getCol(s[0]);
		int ans = 0;
		for (int i = 0; i < 8; ++i) {
			int nrow = row + dr[i];
			int ncol = col + dc[i];
			if (inside(nrow, ncol)) ans += 1;
		}
		std::cout << ans << '\n';
	}
	
	return 0;
}
