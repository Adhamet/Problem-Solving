#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

constexpr int MOD = 1e9 + 7;

int n;
std::vector<int> a;
std::map<std::array<int,3>, i64> mem;

int go(int idx, int lr, int lb) {
	if (idx == n) return 1;

	if (mem.count({idx,lr,lb})) return mem[{idx,lr,lb}];
	i64 &ret = mem[{idx,lr,lb}];
	ret = go(idx + 1, lr, lb);

	if (a[idx] >= lr) ret = (ret + go(idx + 1, a[idx], lb)) % MOD;
	else if (a[idx] >= lb) ret = (ret + go(idx + 1, lr, a[idx])) % MOD;

	return (ret % MOD);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int t;	std::cin >> t;
	while (t--) {
		std::cin >> n;
		a.resize(n);
		for (int i = 0; i < n; ++i) std::cin >> a[i];
		mem.clear();
		std::cout << go(0, 0, 0) << '\n';
	}
	
	return 0;
}
