#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;	std::cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) std::cin >> a[i];

	std::vector<int> ans(n, -1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[j] > a[i]) {
				ans[i] = j+1;
			}
		}
	}

	for (int i = 0; i < n; ++i) std::cout << ans[i] << '\n';
	return 0;
}
