#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int P = 37, M = 1e9+7;

	string s; 
	cin >> s;
	string h = "happiness";
	int n = (int)s.size(), m = (int)h.size();

	vector<int> powa(n+1, 1);
	for (int i = 1; i <= n; ++i)
		powa[i] = int(1LL * powa[i-1] * P % M);

	vector<int> hS(n+1, 0);
	for (int i = 0; i < n; ++i)
		hS[i+1] = int((hS[i] + 1LL*(s[i]-'a'+1)*powa[i]) % M);

	int hH = 0;
	for (int i = 0; i < m; ++i)
		hH = int((hH + 1LL*(h[i]-'a'+1)*powa[i]) % M);
	hH = int(1LL * hH * powa[n - m] % M);

	vector<int> occ;
	for (int i = 0; i + m <= n; ++i) {
		int currH = (hS[i+m] - hS[i] + M) % M;
		currH = int(1LL * currH * powa[n - (i + m)] % M);
		if (currH == hH) {
			occ.push_back(i+1);
			if (occ.size() >= 3) break;
		}
	}

	if (occ.size() >= 3) cout << "NO";
	else if (occ.size() == 1) {
		int l = occ[0], r = occ[0] + m - 1;
		cout << "YES" << el << l << ' ' << r;
	} else if (occ.size() == 2) {
		int l1 = occ[0], l2 = occ[1];
		cout << "YES" << el << l1 << ' ' << (l2 + 1);
	} else {
		vector<int> idx(26, -1);
		for (int i = 0; i < n; ++i) {
			int c = s[i] - 'a';
			if (idx[c] != -1)
				return cout << "YES" << el << idx[c]+1 << ' ' << i + 1, 0;
			idx[c] = i;
		}

		cout << "YES\n1 2";
	}

	return 0;
}
