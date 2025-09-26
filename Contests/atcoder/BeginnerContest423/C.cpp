#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n, r;	std::cin >> n >> r;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) std::cin >> a[i];

	int leftmost = -1;
	for (int i = 1; i <= r; ++i) if (a[i] == 0) {
		leftmost = i;
		break;
	}

	int rightmost = -1;
	for (int i = n; i >= r + 1; --i) if (a[i] == 0) {
		rightmost = i;
		break;
	}

	int ans = 0;
	if (leftmost != -1)
		for (int i = r; i >= leftmost; --i) ans += (a[i] == 0? 1: 2);
	if (rightmost != -1)
		for (int i = r + 1; i <= rightmost; ++i) ans += (a[i] == 0? 1: 2);

	return std::cout << ans, 0;
}
