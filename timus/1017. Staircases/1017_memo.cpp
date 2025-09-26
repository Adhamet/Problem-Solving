#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

constexpr int MXN = 505;

i64 mem[MXN][MXN];

i64 go(int cur, int rem) {
	if (rem == 0) return 1;
	if (cur == 1) return 0;

	i64 &ret = mem[cur][rem];
	if (~ret) return ret;
	ret = 0;

	for (int i = cur - 1; i >= 1; --i) if (rem - i >= 0)
		ret += go(i, rem - i);
	return ret;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	memset(mem, -1, sizeof mem);

	int n;	std::cin >> n;
	std::cout << go(n, n) << '\n';

	return 0;
}
