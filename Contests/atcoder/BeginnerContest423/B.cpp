#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n;	std::cin >> n;
	std::vector<int> a(n+1);
	for (int i = 1; i <= n; ++i) std::cin >> a[i];

	std::vector<int> l(n + 1, 0), r(n + 1, 0);
	l[0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0 && l[i-1] == 1) l[i] = 1;
		else break;
	}

	r[n] = 1;
	for (int i = n; i >= 1; --i) {
		if (a[i] == 0 && r[i]) r[i-1] = 1;
		else break;
	}

	int ans = 0;
	for (int i = 0; i <= n; ++i) if (!l[i] && !r[i]) ans++;
	return std::cout << ans, 0;
}
