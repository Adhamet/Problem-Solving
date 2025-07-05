#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

i64 binexp(i64 b, i64 e, i64 m) {
	i64 r = 1;
	b %= m;
	while (e) {
		if (e & 1) r = r * b % m;
		b = b * b % m;
		e >>= 1;
	} return r;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int P1 = 37, P2 = 39;
	const int M1 = 1e9+7, M2 = 1e9+9;

	string s;	cin >> s;
	string msk;	cin >> msk;
	i64 req;	cin >> req;

	int n = (int)s.size();
	vector<i64> powa1(n), powa2(n);
	powa1[0] = powa2[0] = 1;
	for (int i = 1; i < n; ++i) {
		powa1[i] = powa1[i-1] * P1 % M1;
		powa2[i] = powa2[i-1] * P2 % M2;
	}

	vector<i64> h1(n + 1, 0), h2(n + 1, 0);
	vector<i64> bad(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		if (msk[s[i] - 'a'] == '0')
			bad[i+1] = bad[i] + 1;
		else bad[i+1] = bad[i];
		h1[i + 1] = (h1[i] + (s[i] - 'a' + 1) * powa1[i]) % M1;
		h2[i + 1] = (h2[i] + (s[i] - 'a' + 1) * powa2[i]) % M2;
	}

	i64 ans = 0;
	for (int l = 1; l <= n; ++l) {
		set<pair<i64, i64>> cnt;
		for (int i = 0; i <= n - l; ++i) {
			i64 currB = bad[i + l] - bad[i];
			if (currB <= req) {
				i64 currH1 = (h1[i + l] - h1[i] + M1) % M1;
				i64 currH2 = (h2[i + l] - h2[i] + M2) % M2;
				currH1 = currH1 * powa1[n - i - 1] % M1;
				currH2 = currH2 * powa2[n - i - 1] % M2;
				cnt.insert({currH1, currH2});
			}
		}
		
		ans += (int)cnt.size();
	}

	return cout << ans, 0;
}
