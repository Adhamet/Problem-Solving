#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int32_t _tc;
	cin >> _tc;
	while (_tc--) {
		int32_t n, k, z;
		cin >> n >> k >> z;

		vector<int32_t> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		
		int32_t ans = 0, curr = a[0], bestPair = 0;
		for (int i = 0; i <= k; ++i) {
			if (i > 0) curr += a[i];
			if (i < n - 1) bestPair = max(bestPair, a[i] + a[i + 1]);

			int32_t mxLeft = min(z, (k - i) / 2);
			int32_t currans = curr + (bestPair * mxLeft);
			ans = max(ans, currans);
		}

		cout << ans << el;
	}

	return 0;
}
