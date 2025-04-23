#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const i64 MOD = 1e9+7;

i64 binpow(i64 a, i64 b) {
	if (b == 0) return 1;
	i64 res = 1;
	while (b) {
		if (b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

i64 nCr(i64 n, i64 r) {
	i64 res = 1;
	for (int i = 0; i < min(r, n - r); ++i) {
		res = (res * (n - i)) % MOD;
		res = (res * binpow(i + 1, MOD - 2)) % MOD;
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
		ans = (ans * nCr(places, r)) % MOD;
		places -= r;
	}

	return cout << ans, 0;
}
