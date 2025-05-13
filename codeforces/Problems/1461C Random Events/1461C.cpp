#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while (tc--) {
		int n, m; cin >> n >> m;
		int a[n+1];
		for (int i = 1; i <= n; ++i) cin >> a[i];

		double ans = 0.0, prob = 1.0;
		int li = 0;
		for (int i = n; i>=0; --i) if (a[i]!=i) {
			li = i;
			break;
		}

		if (li == 0) ans = 1.0;
		while (m--) {
			double r, p; cin >> r >> p;
			if (li && r >= li) ans += (prob * p), prob *= (1.0 - p);
		}

		cout << setprecision(6) << fixed << ans << el;
	}

	return 0;
}
