#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int MXN = 2e5;
	const i64 P1 = 31;
	const i64 P2 = 37;
	const i64 M1 = 1e9+7;
	const i64 M2 = 1e9+9;

	vector<i64> powa1(MXN), powa2(MXN);		
	powa1[0] = powa2[0] = 1;
	for (int i = 1; i < MXN; ++i) {
		powa1[i] = powa1[i-1] * P1 % M1;
		powa2[i] = powa2[i-1] * P2 % M2;
	}

	int t;	cin >> t;
	while (t--) {
		int n, k;	cin >> n >> k;
		string s;	cin >> s;

		vector<i64> h1(n + 1, 0), h2(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			h1[i + 1] = (h1[i] + (s[i] - 'a' + 1) * powa1[i]) % M1;
			h2[i + 1] = (h2[i] + (s[i] - 'a' + 1) * powa2[i]) % M2;
		}

		set<pair<i64,i64>> st;
		for (int i = 0; i + k <= n; ++i) {
			i64 currh1 = (h1[i + k] - h1[i] + M1) % M1;
			i64 currh2 = (h2[i + k] - h2[i] + M2) % M2;
			currh1 = (currh1 * powa1[n - (i + k)]) % M1;
			currh2 = (currh2 * powa2[n - (i + k)]) % M2;
			st.insert({currh1, currh2});
		}

		cout << (int)st.size() << el;
	}

	return 0;
}
