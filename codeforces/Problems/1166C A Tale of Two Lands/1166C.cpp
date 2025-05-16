#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] = abs(a[i]);
	}

	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int l = i+1, r = n - 1, bsres = i;
		while (l <= r) {
			int md = (l + r) >> 1;
			if (a[md] <= 2*a[i]) l = md+1, bsres = md;
			else r = md-1;
		}

		ans += (bsres - i);
	}

	return cout << ans, 0;
}
