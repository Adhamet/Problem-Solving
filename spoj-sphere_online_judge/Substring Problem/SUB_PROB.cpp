#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int P1 = 79;
	const int MOD1 = 1e9+7;

	string s;	cin >> s; // patern;
	int szS = (int)s.size();

	vector<i64> powa(szS + 1);	powa[0] = 1;
	for (int i = 1; i <= szS; ++i) powa[i] = (powa[i - 1] * P1) % MOD1;

	vector<i64> hS(szS + 1, 0);
	for (int i = 0; i < szS; ++i)
		hS[i + 1] = (hS[i] + (s[i] - '0' + 1) * powa[i]) % MOD1;

	int q;	cin >> q;
	while (q--) {
		string t;	cin >> t;
		int szT = (int)t.size();

		i64 hT = 0;
		for (int i = 0; i < szT; ++i)
			hT = (hT + (t[i] - '0' + 1) * powa[i]) % MOD1;

		i64 currhS = 0;
		bool acc = false;
		for (int i = 0; i + szT - 1 < szS; ++i) {
			currhS = (hS[i + szT] - hS[i] + MOD1) % MOD1;
			if (currhS == hT * powa[i] % MOD1) {
				acc = true;
				break;
			}
		}

		cout << (acc? 'Y': 'N') << el;
	}

	return 0;
}
