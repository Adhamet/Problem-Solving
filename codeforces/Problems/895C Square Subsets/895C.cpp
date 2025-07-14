#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MOD = 1e9+7;

int n, cnt[71], mem[71][1<<19];
vector<int> primeMsk(71, 0);

i64 modexp(i64 b, i64 e) {
	i64 r = 1;
	b %= MOD;
	while (e) {
		if (e & 1) r = r * b % MOD;
		b = b * b % MOD;
		e >>= 1;
	} return r;
}

i64 go(int val, int msk) {
	if (val == 71) return (msk == 0)? 1: 0;

	int &ret = mem[val][msk];
	if (~ret) return ret;
	ret = 0;

	if (cnt[val] == 0) return ret = go(val + 1, msk);
	i64 ways = modexp(2, cnt[val] - 1);
	ret = (ret + (ways * go(val + 1, msk)) % MOD) % MOD;
	ret = (ret + (ways * go(val + 1, msk ^ primeMsk[val])) % MOD) % MOD;
	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0, x; i < n; ++i) cin >> x, cnt[x]++;

	vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,
							41,43,47,53,59,61,67};
	for (int x = 1; x <= 70; ++x) {
		int msk = 0, y = x;
		for (int i = 0; i < 19; ++i) if (y % primes[i] == 0) {
			int cnt = 0;
			while (y % primes[i] == 0) cnt++, y /= primes[i];
			if (cnt & 1) primeMsk[x] |= (1 << i);
		}
	}

	memset(mem, -1, sizeof mem);	
	i64 ans = go(1, 0);
	return cout << (ans - 1 + MOD) % MOD, 0;
}
