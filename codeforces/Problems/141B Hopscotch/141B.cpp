#include <bits/stdc++.h>
#define el '\n'

int main() {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0);
	int a, x, y, ans;
	std::cin >> a >> x >> y;
	if (y == 0 || abs(x) >= a || y % a == 0) return std::cout << -1, 0;

	int level = (y / a) + 1;
	if (level == 1) {
		if (abs(x) >= ((a + 1) / 2)) ans = -1;
		else ans = 1;
	} else if (level % 2 != 0) {
		int oddLevels = level / 2;
		ans = oddLevels * 2 + (oddLevels - 1) + 2;
		if (x < 0) ans -= 1;
		if (x == 0) ans = -1;
	} else {
		int oddLevels = (level - 1) / 2;
		ans = oddLevels * 2 + (oddLevels + 1) + 1;
		if (abs(x) >= ((a + 1) / 2)) ans = -1;
	}

	std::cout << ans;
	return 0;
}
