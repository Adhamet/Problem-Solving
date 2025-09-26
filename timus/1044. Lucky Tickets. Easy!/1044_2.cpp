#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int hn;
i64 mem[5][int(9*5)];

i64 go(int idx, int sm) {
	if (idx == hn) return (sm == 0);

	i64 &ret = mem[idx][sm];
	if (~ret) return ret;
	ret = 0;

	for (int x = 0; x <= 9; ++x) if (sm - x >= 0)
		ret += go(idx + 1, sm - x);
	return ret;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n;	std::cin >> n;
	hn = n / 2;

	std::vector<int> ways(9 * hn + 1, 0);
	for (int sm = 0; sm <= 9 * hn; ++sm) {
		memset(mem, -1, sizeof mem);
		ways[sm] = go(0, sm);
	}

	i64 ans = 0;
	for (int sm = 0; sm <= 9 * hn; ++sm)
		ans += ways[sm] * ways[sm];
	
	return std::cout << ans, 0;
}
