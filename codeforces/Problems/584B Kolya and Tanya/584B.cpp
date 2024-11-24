#include <bits/stdc++.h>
using ll = long long;
#define el '\n'
int main() {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0);
	ll n, a = 1, b = 1, MOD = 1e9+7;
	std::cin >> n;
	for (int i = 0; i < n * 3; i++) a = (a * 3) % MOD;
	for (int i = 0; i < n; i++) b = (b * 7) % MOD;
	std::cout << (a - b + MOD) % MOD;
	return 0;
}
