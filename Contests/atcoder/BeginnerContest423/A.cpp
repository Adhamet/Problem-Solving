#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	i64 x, c;	std::cin >> x >> c;
	i64 k = x / (c + 1000);
	std::cout << k * 1000;
	return 0;
}
