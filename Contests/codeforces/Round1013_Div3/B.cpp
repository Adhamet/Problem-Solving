#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		sort(a.rbegin(), a.rend());

		int len = 1, ans = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] * len >= x) {
				len = 1;
				ans += 1;
			} else len += 1;
		}

		cout << ans << el;
	}

	return 0;
}
