#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, w; cin >> n >> w;
	vector<i64> b(n), e(w);
	for (int i = 0; i < n; ++i) cin >> b[i];
	for (int i = 0; i < w; ++i) cin >> e[i];

	if (w == 1) return cout << n, 0;
	
	vector<i64> db(n - 1), de(w - 1);
	for (int i = 0; i + 1 < n; ++i) db[i] = b[i] - b[i + 1];
	for (int i = 0; i + 1 < w; ++i) de[i] = e[i] - e[i + 1];

	vector<i64> t;
	for (auto &x: de) t.push_back(x);
	t.push_back(1e18);
	for (auto &x: db) t.push_back(x);

	int k = t.size();
	vector<int> z(k);    z[0] = k;
	int l = 0, r = 0;
	for (int i = 1; i < k; ++i) {
		if (i < r) z[i] = min(r - i, z[i - l]);
		while (i + z[i] < k && t[z[i]] == t[i + z[i]]) ++z[i];
		if (i + z[i] > r) l = i, r = i + z[i];
	}

	int ans = 0;
	for (int i = w; i < k; ++i) if (z[i] == w - 1) ++ans;
	return cout << ans, 0;
}
