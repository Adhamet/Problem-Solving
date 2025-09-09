#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		map<int, i64> v, h, md, ad;
		for (int i = 0, x, y; i < n; ++i) {
			cin >> x >> y;
			v[x]++, h[y]++;
			md[x-y]++, ad[x+y]++;
		}

		i64 ans = 0;
		for (auto &pr: v) ans += pr.second * (pr.second - 1);
		for (auto &pr: h) ans += pr.second * (pr.second - 1);
		for (auto &pr: md) ans += pr.second * (pr.second - 1);
		for (auto &pr: ad) ans += pr.second * (pr.second - 1);
		cout << ans << '\n';
	}

	return 0;
}
