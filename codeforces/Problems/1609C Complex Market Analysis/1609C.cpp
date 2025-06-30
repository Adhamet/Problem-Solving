#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		i64 n, e;	cin >> n >> e;
		vector<i64> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		i64 ans = 0;
		for (int i = 0; i < n; ++i) {
			i64 k = 0, curr = a[i], cnt = 0;
			while (k < n && i + e * k < n) {
				curr *= a[i + e * k];
				++k;
				if (isPrime[curr]) cnt += 1;
			}

			ans += (cnt + 1);
		}

		cout << ans << el;
	}

	return 0;
}
