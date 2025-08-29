#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int MXN = 2e5 + 5;
	constexpr i64 MOD = 998244353, oo = INT64_MAX;

	auto binexp = [&](i64 b, i64 e) {
		i64 r = 1;
		b %= MOD;
		while (e) {
			if (e & 1) r = r * b % MOD;
			b = b * b % MOD;
			e >>= 1;
		}
		return r;
	};

	vector<i64> fact(MXN), invFact(MXN);
	fact[0] = 1;
	for (int i = 1; i < MXN; ++i) fact[i] = fact[i - 1] * i % MOD;
	invFact[MXN-1] = binexp(fact[MXN-1], MOD - 2);
	for (int i = MXN-1; i > 0; --i) invFact[i-1] = invFact[i] * i % MOD;

	auto nPr = [&](int n, int r) -> i64 {
		if (r > n || r < 0) return 0;
		return fact[n] * invFact[n - r] % MOD;
	};

	auto add = [&](i64 a, i64 b) { return (a+b+MOD)%MOD; };
	auto mul = [&](i64 a, i64 b) { return (a*b)%MOD; };

	int t; 	cin >> t;
	while (t--) {
		int n; 	cin >> n;
		vector<i64> a(n);
		map<i64,int> freq;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			freq[a[i]]++;
		}

		i64 mx = -oo, secMax = -oo;
		for (auto &kv: freq) {
			if (kv.first > mx) secMax = mx, mx = kv.first;
			else if (kv.first > secMax) secMax = kv.first;
		}

		int cntMax = freq[mx];
		int cntSecMax = (secMax == oo? 0: freq[secMax]);

		if (cntMax > 1) {
			cout << fact[n] % MOD << '\n';
			continue;
		}
		
		if (secMax + 1 != mx) {
			cout << 0 << '\n';
			continue;
		}
		
		i64 ans = fact[n];
		for (int i = cntSecMax; i < n; ++i)
			ans = add(ans, -mul(nPr(i, cntSecMax), fact[n - 1 - cntSecMax]));
		cout << ans % MOD << '\n';
	}

	return 0;
}
