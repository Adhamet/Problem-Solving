#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

i64 binexp(i64 b, i64 e, i64 m) {
	i64 r = 1;
	b %= m;
	while (e) {
		if (e & 1) r = (r * b) % m;
		b = (b * b) % m;
		e >>= 1;
	}
	return r;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const i64 P1 = 37, P2 = 39;
	const i64 M1 = 1e9 + 7, M2 = 1e9 + 9;

	int n, k;	cin >> n >> k;
	string s;	cin >> s;
	int len = n * k;

	s += s.substr(0, k - 1);

	int K = s.size();
	vector<i64> powa1(K), powa2(K);
	powa1[0] = powa2[0] = 1;
	for (int i = 1; i < K; i++) {
		powa1[i] = powa1[i - 1] * P1 % M1;
		powa2[i] = powa2[i - 1] * P2 % M2;
	}

	vector<i64> h1(K + 1, 0), h2(K + 1, 0);
	for (int i = 0; i < K; i++) {
		h1[i + 1] = (h1[i] + (s[i] - 'a' + 1) * powa1[i]) % M1;
		h2[i + 1] = (h2[i] + (s[i] - 'a' + 1) * powa2[i]) % M2;
	}

	int g;	cin >> g;
	map<pair<i64, i64>, int> hashIdx;
	for (int i = 1; i <= g; i++) {
		string t;	cin >> t;
		i64 hT1 = 0, hT2 = 0;
		for (int j = 0; j < k; j++) {
			hT1 = (hT1 + (t[j] - 'a' + 1) * powa1[j]) % M1;
			hT2 = (hT2 + (t[j] - 'a' + 1) * powa2[j]) % M2;
		}

		hashIdx[{hT1, hT2}] = i;
	}

	for (int start = 0; start < k; start++) {
		set<int> vis;
		vector<int> res;

		bool acc = true;
		for (int i = 0; i < n; i++) {
			int l = start + i * k;
			int r = l + k;
			if (r > (int)s.size()) {
				acc = false;
				break;
			}

			i64 rH1 = (h1[r] - h1[l] + M1) % M1;
			i64 rH2 = (h2[r] - h2[l] + M2) % M2;
			rH1 = rH1 * binexp(powa1[l], M1 - 2, M1) % M1;
			rH2 = rH2 * binexp(powa2[l], M2 - 2, M2) % M2;
			if (!hashIdx.count({rH1, rH2}) || vis.count(hashIdx[{rH1, rH2}])) {
				acc = false;
				break;
			}

			vis.insert(hashIdx[{rH1, rH2}]);
			res.push_back(hashIdx[{rH1, rH2}]);
		}

		if (acc) {
			cout << "YES\n";
			for (int &x: res) cout << x << ' ';
			return 0;
		}
	}

	return cout << "NO", 0;
}
