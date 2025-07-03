#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const i64 P = 31;
	const i64 MOD = 1e9+9;

	int n;
	string t, s;
	while (cin >> n >> t >> s) { // t: text, s: haystack
		int szS = (int)s.size();
		vector<i64> powa(max(n, szS));
		powa[0] = 1;
		for (int i = 1; i < (int)powa.size(); ++i)
			powa[i] = (powa[i - 1] * P) % MOD;

		i64 hT = 0;
		for (int i = 0; i < n; ++i)
			hT = (hT + (t[i] - 'a' + 1) * powa[i]) % MOD;
		vector<i64> hS(szS + 1, 0);
		for (int i = 0; i < szS; ++i)
			hS[i + 1] = (hS[i] + (s[i] - 'a' + 1) * powa[i]) % MOD;

		i64 currHS;
		for (int i = 0; i + n - 1 < szS; ++i) {
			currHS = (hS[i + n] - hS[i] + MOD) % MOD;
			if (currHS == (hT * powa[i]) % MOD) cout << i << el;
		} cout << el;
	}

	return 0;
}
