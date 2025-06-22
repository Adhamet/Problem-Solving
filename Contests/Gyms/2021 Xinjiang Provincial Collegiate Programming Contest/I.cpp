#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	vector<i64> a(n), b(m);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	sort(b.begin(), b.end());

	i64 L, R, ans = 0; cin >> L >> R;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			if (L <= 0 && 0 <= R) ans += m;
			continue;
		}

		double l = a[i]>0? (double)L/a[i]: (double)R/a[i];
		double r = a[i]>0? (double)R/a[i]: (double)L/a[i];
		i64 lb = ceil(l), rb = floor(r);
		if (lb > rb) continue;
		auto it1 = lower_bound(b.begin(), b.end(), lb);
		auto it2 = upper_bound(b.begin(), b.end(), rb);
		ans += it2 - it1;
	}

	return cout << ans, 0;
}
