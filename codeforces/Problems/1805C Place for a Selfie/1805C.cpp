#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, m;	cin >> n >> m;
		vector<i64> coef(n);
		for (int i = 0; i < n; ++i) cin >> coef[i];
		sort(coef.begin(), coef.end());

		for (int i = 0; i < m; ++i) {
			i64 a, b, c;	cin >> a >> b >> c;

			i64 rhs = 4 * a * c, ans = -1;
			auto it = upper_bound(coef.begin(), coef.end(), b);
			bool acc = false;
			
			if (it != coef.end()) {
				i64 lhs = (b - *it) * (b - *it);
				if (lhs < rhs) acc = true, ans = *it;
			}

			if (!acc && it != coef.begin()) {
				--it;
				i64 lhs = (b - *it) * (b - *it);
				if (lhs < rhs) acc = true, ans = *it;
			}

			if (acc) cout << "YES\n" << ans << "\n";
			else cout << "NO\n";
		}

		cout << "\n";
	}

	return 0;
}
