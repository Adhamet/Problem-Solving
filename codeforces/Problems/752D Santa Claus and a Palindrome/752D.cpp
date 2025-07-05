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

	const i64 P = 37, M = 1e9 + 9;

	int k, n;	cin >> k >> n;
	vector<i64> powa(n);
	powa[0] = 1;
	for (int i = 1; i < n; ++i) powa[i] = powa[i - 1] * P % M;

	unordered_map<i64, vector<i64>> selfPalis;
	map<pair<i64, i64>, vector<i64>> nonPalis;

	for (int i = 0; i < k; ++i) {
		string s;	cin >> s;
		i64 a;	cin >> a;
		i64 h = 0, rh = 0;
		for (int j = 0; j < n; ++j) {
			h = (h + (s[j] - 'a' + 1) * powa[j]) % M;
			rh = (rh + (s[n - j - 1] - 'a' + 1) * powa[j]) % M;
		}

		if (h == rh) selfPalis[h].push_back(a);
		else nonPalis[{h, rh}].push_back(a);
	}

	i64 ans = 0;

	set<pair<i64, i64>> visited;
	for (auto &[p, vec] : nonPalis) {
		auto [h1, h2] = p;
		if (visited.count(p) || visited.count({h2, h1})) continue;
		if (!nonPalis.count({h2, h1})) continue;

		auto &v1 = vec;
		auto &v2 = nonPalis[{h2, h1}];
		sort(v1.rbegin(), v1.rend());
		sort(v2.rbegin(), v2.rend());
		int sz = min((int)v1.size(), (int)v2.size());
		for (int i = 0; i < sz; ++i) {
			if (v1[i] + v2[i] > 0) ans += v1[i] + v2[i];
			else break;
		}

		visited.insert(p);
		visited.insert({h2, h1});
	}

	i64 mx = 0;
	for (auto &[h, pr] : selfPalis) {
		sort(pr.begin(), pr.end());
		while (pr.size() > 1) {
			i64 t1 = pr.back(); pr.pop_back();
			i64 t2 = pr.back(); pr.pop_back();
			if (t1 <= 0) break;
			if (t1 >= 0 && t2 >= 0) ans += t1 + t2;
			else if (t1 + t2 >= 0) {
				ans += t1 + t2;
				mx = max(mx, -t2);
			} else mx = max(mx, t1);
		}

		if ((int)pr.size() == 1) mx = max(mx, pr[0]);
	}

	ans += mx;
	return cout << ans, 0;
}

