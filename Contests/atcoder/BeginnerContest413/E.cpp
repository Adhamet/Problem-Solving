#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

vector<int> compute(vector<int>& v, int l, int r) {
	if (r - l == 1) return vector<int>{v[l]};

	int m = (l + r) >> 1;
	vector<int> L = compute(v, l, m);
	vector<int> R = compute(v, m, r);

	vector<int> cand1;
	cand1.insert(cand1.end(), L.begin(), L.end());
	cand1.insert(cand1.end(), R.begin(), R.end());

	vector<int> cand2;
	cand2.insert(cand2.end(), R.begin(), R.end());
	cand2.insert(cand2.end(), L.begin(), L.end());
	return cand1 < cand2? cand1: cand2;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		int m = 1 << n;

		vector<int> p(m);
		for (int i = 0; i < m; ++i) cin >> p[i];

		vector<int> ans = compute(p, 0, m);
		for (int i = 0; i < m; ++i) cout << ans[i] << ' ';
		cout << el;
	}

	return 0;
}
