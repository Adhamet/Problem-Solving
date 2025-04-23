#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const i64 MOD = 1e9+6;

i64 extendedGCD(i64 a, i64 b, i64 &x, i64 &y) {
	x = 1, y = 0;
	i64 nx = 0, ny = 1, a1 = a, b1 = b;
	while (b) {
		i64 q = (a / b);
		tie(x, nx) = make_tuple(nx, x - q * nx);
		tie(y, ny) = make_tuple(ny, y - q * ny);
		tie(a1, b1) = make_tuple(b1, a1 - q * b1);
	}
	return a1;
}

i64 modInverse(i64 a, i64 b) {
	i64 x, y;
	i64 g = extendedGCD(a, b, x, y);
	if (g != 1) return -1;
	return (x % b + b) % b;
}

i64 nCr(i64 n, i64 r) {
	i64 res = 1;
	for (int i = 0; i < min(r, n - r); ++i) {
		res = (res * (n - i)) % MOD;
		i64 inv = modInverse(i + 1, MOD);
		if (inv == -1) return -1;
		res = (res * inv) % MOD;
	}
	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	i32 n = (i32)s.size();

	map<int, int> freq;
	for (int i = 1; i < n; ++i) freq[s[i] - 'a'] += 1;

	i64 ans = 1, places = n - 1;
	for (auto &[x, r]: freq) {
		i64 nCrRES = nCr(places, r);
		if (nCrRES == -1) {
			ans = -1;
			break;
		} 
		ans = (ans * nCrRES) % MOD;
		places -= r;
	}

	return cout << ans, 0;
}

