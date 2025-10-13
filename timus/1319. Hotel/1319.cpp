#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;	std::cin >> n;
	int a[n][n]{};
	int cur = 1;

	for (int j = n - 1; j >= 0; --j) {
		int x = 0, y = j;
		while (x < n && y < n) {
			a[x][y] = cur++;
			++x; ++y;
		}
	}

	for (int i = 1; i < n; ++i) {
		int x = i, y = 0;
		while (x < n && y < n) {
			a[x][y] = cur++;
			++x; ++y;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			std::cout << a[i][j] << ' ';
		std::cout << '\n';
	}

	return 0;
}
