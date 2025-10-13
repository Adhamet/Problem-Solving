#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;	std::cin >> n;
	int a[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x;
			std::cin >> x;
			a[i][j] = x;
		}
	}

	auto inside = [&](int r, int c) { return r >= 0 && r < n && c >= 0 && c < n; };
	for (int i = 0; i < n; ++i) {
		int nx = i, ny = 0;
		while (inside(nx, ny)) {
			std::cout << a[nx][ny] << ' ';
			nx -= 1;
			ny += 1;
		}
	}
	for (int j = 1; j < n; ++j) {
		int nx = n - 1, ny = j;
		while (inside(nx, ny)) {
			std::cout << a[nx][ny] << ' ';
			nx -= 1;
			ny += 1;
		}
	}
	
	return 0;
}
