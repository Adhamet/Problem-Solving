#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int P = 31;
	const int MOD = 1e9+9;

	string s;	cin >> s;
	int n = (int)s.size();
	vector<i64> powa(n, 0);		powa[0] = 1;
	for (int i = 1; i < n; ++i) powa[i] = powa[i - 1] * P % MOD;

	vector<i64> hS(n + 1, 0);
	for (int i = 0; i < n; ++i)
		hS[i + 1] = (hS[i] + (s[i] - 'a' + 1) * powa[i]) % MOD;

	string ans = "";
	for (int l = n; l >= 1; --l) {
		i64 fHS = (hS[l] - hS[0] + MOD) % MOD;
		i64 sHS = (hS[n] - hS[n - l] + MOD) % MOD;
		fHS = (fHS * powa[n - l]) % MOD;

		if (fHS == sHS) {
			for (int j = 1; j + l < n; ++j) {
				i64 tHS = (hS[j + l] - hS[j] + MOD) % MOD;
				tHS = tHS * powa[n - l - j] % MOD;
				if (tHS == fHS) {
					ans = s.substr(0, l);
					break;
				}
			}
		}

		if (ans != "") break;
	}

	return cout << (ans != ""? ans: "Just a legend"), 0;
}
