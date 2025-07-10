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
	}
	return r;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int MAXN = 1e6 + 5;
	const i64 P1 = 31, M1 = 1e9 + 7;
	const i64 P2 = 37, M2 = 1e9 + 9;

	vector<i64> powa1(MAXN, 0), powa2(MAXN, 0);
	powa1[0] = powa2[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		powa1[i] = powa1[i - 1] * P1 % M1;
		powa2[i] = powa2[i - 1] * P2 % M2;
	}

	vector<i64> invpowa1(MAXN, 0), invpowa2(MAXN, 0);
	invpowa1[MAXN - 1] = binexp(powa1[MAXN - 1], M1 - 2, M1);
	invpowa2[MAXN - 1] = binexp(powa2[MAXN - 1], M2 - 2, M2);
	for (int i = MAXN - 2; i >= 0; --i) {
		invpowa1[i] = invpowa1[i + 1] * P1 % M1;
		invpowa2[i] = invpowa2[i + 1] * P2 % M2;
	}

	int t;	cin >> t;
	while (t--) {
		string s, t; cin >> s >> t;
		int n = (int)s.size(), m = (int)t.size();

		vector<i64> hS1(n + 1, 0), hS2(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			hS1[i + 1] = (hS1[i] + (s[i] - 'a' + 1) * powa1[i]) % M1;
			hS2[i + 1] = (hS2[i] + (s[i] - 'a' + 1) * powa2[i]) % M2;
		}

		i64 hT1 = 0, hT2 = 0;
		for (int i = 0; i < m; ++i) {
			hT1 = (hT1 + (t[i] - 'a' + 1) * powa1[i]) % M1;
			hT2 = (hT2 + (t[i] - 'a' + 1) * powa2[i]) % M2;
		}

		vector<int> ans;
		for (int i = 0; i + m <= n; ++i) {
			i64 currH1 = (hS1[i + m] - hS1[i] + M1) % M1;
			currH1 = (currH1 * invpowa1[i]) % M1;
			i64 currH2 = (hS2[i + m] - hS2[i] + M2) % M2;
			currH2 = (currH2 * invpowa2[i]) % M2;
			if (currH1 == hT1 && currH2 == hT2) ans.push_back(i + 1);
		}

		if (ans.empty()) cout << "Not Found\n";
		else {
			cout << (int)ans.size() << el;
			for (int i : ans) cout << i << ' ';
			cout << el;
		} cout << el;
	}

	return 0;
}

